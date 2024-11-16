#include "UniformVarianble.h"

UniformVariable::UniformVariable(GLuint shader_program, GLint uniform_location)
{
	this->shader_program = shader_program;
	this->uniform_location = uniform_location;
}
