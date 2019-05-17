#pragma once

#include "GLFW/glfw3.h"
#include "../../Headers.h"
#include "../Component.h"
#include "../../Graphics/Texture.h"

#include <iostream>
#include <list>
#include<string>

using namespace std;

class SpriteRenderer : public Component
{
public:
	SpriteRenderer(string path, int width, int height);
	SpriteRenderer(string path[], int length, float updateTimer, int width, int height);

	void Start();
	void Update();
	void Render();

private:
	list<Texture> textures;
	int width;
	int height;
	int index;
	float curUpdateTimer;
	float updateTimer;
};
