#version 100

precision lowp float;

varying vec2 uv;
uniform vec3 color;
uniform sampler2D albedo;
void main() {
  vec4 sampledColor = texture2D(albedo, uv);
  if (sampledColor.a == 0.0)
    discard;
  gl_FragColor = vec4(color, 1.0) * sampledColor;
}
