#include "Engine.h"

int Engine::SCREEN_WIDTH = 960;
int Engine::SCREEN_HEIGHT = 600;

GLFWwindow* Engine::window = NULL;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(const char* title)
{
	if (!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title, NULL, NULL);

	if (window == NULL)
	{
		cout << "Error creating window" << endl;
		return false;
	}

	// GLFW Setup
	glfwMakeContextCurrent(window);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	// Buffer swap every frame
	glfwSwapInterval(1);

	const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (vidMode->width - SCREEN_WIDTH) / 2;
	int yPos = (vidMode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	// GL Setup

	// Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	// Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::Update()
{
	glfwPollEvents();
}

void Engine::BeginRender()
{
	glClearColor(0, 0, 1, 1);
	// Clear color and depth
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender()
{
	glfwSwapBuffers(window);
}