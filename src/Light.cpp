#include <GLES2/gl2.h>
#include<sstream>
#include <Light.h>
#include <Renderer.h>
using namespace aw;
using namespace std;
using namespace glm;

map<string,GLuint> Light::uniforms;
Light::Light(vec4 ambient, vec4 diffuse, vec4 specular, LightType type, vec3 position, vec3 direction,
			 float angle, GameObject *parent) : parent(parent)
{
	lightStruct.ambient = ambient;
	lightStruct.angle = angle / 2.0f;
	lightStruct.diffuse = diffuse;
	lightStruct.direction = direction;
	lightStruct.enabled = true;
	lightStruct.position = position;
	lightStruct.specular = specular;
	lightStruct.type = type;
	transform = Transform(position, direction);
}
void Light::update()
{
	LightStruct tempStruct=lightStruct;
	if (lightStruct.type == LightType::SPOT)
	{
		tempStruct.position = parent->applyTransform() * vec4(transform.getPosition(), 1);
		tempStruct.direction = parent->applyTransform() * vec4(lightStruct.direction, 0);
	}
	glUniform1i(getUniformLocation(getFormattedMember("enabled").c_str()),tempStruct.enabled);
	glUniform1i(getUniformLocation(getFormattedMember("type").c_str()),tempStruct.type);
	glUniform4fv(getUniformLocation(getFormattedMember("ambient").c_str()),1,&tempStruct.ambient.x);
	glUniform4fv(getUniformLocation(getFormattedMember("diffuse").c_str()),1,&tempStruct.diffuse.x);
	glUniform4fv(getUniformLocation(getFormattedMember("specular").c_str()),1,&tempStruct.specular.x);
	glUniform3fv(getUniformLocation(getFormattedMember("direction").c_str()),1,&tempStruct.direction.x);
	glUniform1f(getUniformLocation(getFormattedMember("angle").c_str()),tempStruct.angle);
	glUniform3fv(getUniformLocation(getFormattedMember("position").c_str()),1,&tempStruct.position.x);
	assert(glGetError() == 0);
}
void Light::toggle()
{
	lightStruct.enabled = !lightStruct.enabled;
	//update();
}
Light::~Light()
{
}
void Light::setupIndices(vector<Light> &lights)
{
	if (lights.size() > MAX_LIGHTS)
	{
		printf("requested more lights (%li) than the specified limit, ignoring past %d lights",
			   lights.size(),MAX_LIGHTS);
	}
	for (unsigned i = 0; i < lights.size(); ++i)
	{
		lights[i].index = i;
		lights[i].update();
	}
}

GLuint Light::getUniformLocation(const char* name){
	auto it=uniforms.find(name);
	if(it==uniforms.end()){
		GLuint location=RENDERER.getUniformLocation(name);
		uniforms.insert({name,location});
		return location;
	}else{
		return it->second;
	}
}

string Light::getFormattedMember(const char* member){
	stringstream s;
	s<<"lights["<<index<<"]."<<member;	
	return s.str();
}
