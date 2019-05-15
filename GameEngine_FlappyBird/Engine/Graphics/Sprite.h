#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include<string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string path);
	Sprite(string path, float _xPos, float _yPos);

	void Update();
	void Render();

private:
	Texture texture;
	float xPos;
	float yPos;
	float zRot;
	float scale;
};

#endif