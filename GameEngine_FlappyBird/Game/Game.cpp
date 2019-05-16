#pragma once

#include "../Engine/Engine.h"
#include "../Engine/Headers.h"
#include "ComponentHeaders.h"

#include <iostream>
using namespace std;

int main()
{
	Engine engine;
	engine.Initialize("Flappy Bird Game");

	Object* birdObj = new Object();
	Bird* bird = new Bird();
	SpriteRenderer* renderer = new SpriteRenderer("Assets/Bird/Flying/frame-1.png", 100, 103);
	birdObj->AddComponent(bird);
	birdObj->AddComponent(renderer);
	engine.AddObject(birdObj);

	while (true && engine.ShouldClose() == false)
	{
		engine.Update();

		engine.BeginRender();

		engine.Render();

		engine.EndRender();
	}

	return 0;
}