#pragma once

#include "GLFW/glfw3.h"
#include "../../Headers.h"
#include "../Component.h"
#include "../../Graphics/Texture.h"

#include <iostream>
#include<string>

using namespace std;

class SpriteRenderer : public Component
{
public:
	SpriteRenderer(string path, int width, int height);

	void Update();
	void Render();

private:
	Texture texture;
	int width;
	int height;
};
