#version 100

attribute vec3 positionModel;
attribute vec3 normalModel;
attribute vec2 texCoord;
varying vec2 texCoordOut;
varying vec3 normalWorld, fragWorld;

uniform mat4 VP, M, transformedM; //FIXME send transpose(inverse(M)) as transformedM

void main() {
  fragWorld = vec3(M * vec4(positionModel, 1));
  gl_Position = VP * vec4(fragWorld, 1);
  normalWorld = vec3(transformedM * vec4(normalModel, 0));
  texCoordOut = texCoord;
}