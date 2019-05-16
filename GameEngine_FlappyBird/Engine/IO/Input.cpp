#include "Input.h"

Input* Input::instance = NULL; 

Input::Input(GLFWwindow* _window)
{
	window = _window;
	Input::instance = this;
}

void Input::Update()
{
	for (int i = GLFW_KEY_UNKNOWN; i < GLFW_KEY_LAST; i++)
	{
		int previous = keyboardkeys[i].pressed;
		keyboardkeys[i].pressed = glfwGetKey(window, i);
		if (keyboardkeys[i].pressed && !previous)
		{
			keyboardkeys[i].down = true;
		}
		else
		{
			keyboardkeys[i].down = false;
		}

		if (!keyboardkeys[i].pressed && previous)
		{
			keyboardkeys[i].up = true;
		}
		else
		{
			keyboardkeys[i].up = false;
		}
	}
}

bool Input::GetKey(int key)
{
	return keyboardkeys[key].pressed;
}

bool Input::GetKeyUp(int key)
{
	return keyboardkeys[key].up;
}

bool Input::GetKeyDown(int key)
{
	return keyboardkeys[key].down;
}