#pragma once

#include "IO/Input.h"
#include "Objects/Object.h"

#include <GLFW/glfw3.h>
#pragma comment (lib, "opengl32.lib")

#include <iostream>
#include <list>
using namespace std;

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);

	void Update();

	void BeginRender();
	void Render();
	void EndRender();

	bool ShouldClose();

	void AddObject(Object* object);

private:
	static GLFWwindow* window;

	list<Object*> objects;
};