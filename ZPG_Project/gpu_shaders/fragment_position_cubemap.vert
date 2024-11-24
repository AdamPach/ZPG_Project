#version 330

uniform samplerCube textureUnitID;

in vec3 TexCoords;

out vec4 frag_colour;

void main () {
     frag_colour = texture(textureUnitID, TexCoords);
}