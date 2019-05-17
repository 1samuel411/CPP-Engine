#pragma once

#include "IO/Input.h"
#include "Objects/Object.h"
#include "Structures/Structures.h"

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
	static Vector2 cameraPos;
	static float zoom;

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