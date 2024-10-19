#include "FragmentShader.h"

FragmentShader::FragmentShader(const char* shader_source)
{
	shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader, 1, &shader_source, 0);
	glCompileShader(shader);
}
