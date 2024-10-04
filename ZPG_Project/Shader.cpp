#include "Shader.h"

void Shader::AttachShader(GLuint shader_program)
{
	glAttachShader(shader_program, shader);
}
