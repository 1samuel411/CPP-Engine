#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h";

#include <iostream>
using namespace std;

int main()
{
	Engine engine;
	engine.Initialize("Flappy Bird Game");

	Sprite sprite = Sprite("Assets/Bird/Flying/frame-1.png", -100, -100);

	while (true)
	{
		engine.Update();
		sprite.Update();

		engine.BeginRender();

		sprite.Render();

		engine.EndRender();
	}

	return 0;
}