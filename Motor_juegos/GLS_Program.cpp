#include "GLS_Program.h"
#include <vector>
#include <fstream>

void GLS_Program::compileShader(const string& shaderPath, GLuint id)
{
	string fileContent = "";
	string line = "";
	ifstream shaderFile(shaderPath);
	if (shaderFile.fail())
	{
		// TODO implementar mensaje de error 
	}
	while (getline(shaderFile,line))
	{
		fileContent += line;
	}
	shaderFile.close();
	const char* contents = fileContent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);
	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
		glDeleteShader(id);
		return;
	}
}

GLS_Program::GLS_Program()
{
}

GLS_Program::~GLS_Program()
{
}

void GLS_Program::compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath)
{
	programID = glCreateProgram();
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	compileShader(vertexShaderFilePath, vertexShaderID);
	compileShader(fragmentShaderFilePath, fragmentShaderID);
}

void GLS_Program::linkShader()
{
}
