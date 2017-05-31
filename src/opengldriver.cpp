#include "opengldriver.h"


OpenGLDriver::OpenGLDriver()
{

	
}

OpenGLDriver::~OpenGLDriver()
{
}

void OpenGLDriver::resize(ScreenInfo info)
{

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_screenInfo.m_width, m_screenInfo.m_height, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_depth, 0);

		
}


void OpenGLDriver::initializeDriver()
{
	glClearColor(0.0, 0.1, 0.6, 0.0);
	glewExperimental = GL_TRUE;
	glewInit();
}

void OpenGLDriver::loadShaders()
{
	m_vert = glCreateShader(GL_VERTEX_SHADER);
	m_frag = glCreateShader(GL_FRAGMENT_SHADER);
	std::string vert = FileLoader::loadFile("shaders/vs_general.glsl");
	std::string frag = FileLoader::loadFile("shaders/fs_general.glsl");

	
	
}

void OpenGLDriver::run()
{

	GLuint vertarray;
	glGenVertexArrays(1, &vertarray);
	glBindVertexArray(vertarray);
	//render scene here
	//temp triangle
	GLfloat verts[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};  
	GLuint vertices;
	glGenBuffers(1, &vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	

	
}

