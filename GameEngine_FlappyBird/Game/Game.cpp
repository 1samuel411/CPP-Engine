#pragma once

#include "../Engine/Engine.h"
#include "../Engine/Headers.h"
#include "ComponentHeaders.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	Engine engine;
	engine.Initialize("Flappy Bird Game");

	Object* birdObj = new Object();
	birdObj->transform->position.x = 50;
	birdObj->transform->position.y = Engine::SCREEN_HEIGHT/2 - 50;
	engine.AddObject(birdObj);

	string flyFrames[8] = { "Assets/Bird/Flying/frame-1.png", "Assets/Bird/Flying/frame-2.png", "Assets/Bird/Flying/frame-3.png", "Assets/Bird/Flying/frame-4.png", "Assets/Bird/Flying/frame-5.png", "Assets/Bird/Flying/frame-6.png", "Assets/Bird/Flying/frame-7.png", "Assets/Bird/Flying/frame-8.png" };
	SpriteRenderer* renderer = new SpriteRenderer(flyFrames, 8, 75, 100, 103);
	birdObj->AddComponent(renderer);

	Rigidbody* rigidbody = new Rigidbody();
	birdObj->AddComponent(rigidbody);

	Bird* bird = new Bird();
	birdObj->AddComponent(bird);

	birdObj->Start();
	
	while (true && engine.ShouldClose() == false)
	{
		engine.Update();

		engine.BeginRender();

		engine.Render();

		engine.EndRender();

		this_thread::sleep_for(chrono::milliseconds((int)Time::instance->GetUpdateTime()));

		Time::instance->EndLoop();
	}

	return 0;
}