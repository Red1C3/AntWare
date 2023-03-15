#pragma once
#include<GLES2/gl2.h>
#include <glm/glm.hpp>
namespace aw
{
	class Material
	{
	private:
		glm::vec4 ambient, diffuse, specular;
		float shininess, alpha = 1.0f;
		static GLint ambientLoc, diffuseLoc, specularLoc, shininessLoc,alphaLoc;

	public:
		Material(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float shininess);
		Material();
		void setAmbient(glm::vec4 ambient);
		void setDiffuse(glm::vec4 diffuse);
		void setSpecular(glm::vec4 specular);
		void setShininess(float shininess);
		void setAlpha(float alpha);
		float getAlpha();
		void apply();

		static void setUniformsLocation(GLuint program);
	};
}