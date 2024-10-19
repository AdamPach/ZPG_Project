#include "VertexShader.h"

VertexShader::VertexShader(const char* shader_source)
{
	shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader, 1, &shader_source, 0);
	glCompileShader(shader);
}
