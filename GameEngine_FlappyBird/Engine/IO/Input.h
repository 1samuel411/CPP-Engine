#pragma once

#include "GLFW/glfw3.h"
#include <map>
#include <iostream>

using namespace std;

class Input
{
	struct InputKey
	{
		bool up;
		bool down;
		bool pressed;
	};

public:
	Input(GLFWwindow* window);
	bool GetKey(int key);
	bool GetKeyUp(int key);
	bool GetKeyDown(int key);
	void Update();
	static Input* instance;

private:
	GLFWwindow* window;
	map<int, InputKey> keyboardkeys;
};