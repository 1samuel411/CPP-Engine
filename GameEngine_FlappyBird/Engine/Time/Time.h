#pragma once

#include <cstddef>
#include <chrono>

using namespace std;

class Time
{
public:
	static Time* instance;
	void BeginRunning();
	void EndLoop();

	double GetUpdateTime();
	static double GetFPS();
	static double GetDeltaTime();
	static long GetTimeRunning();
	static void SetTargetFPS(int target);

private:
	long beginTime;
	long lastFrameTime;
	double deltaTime;
	double fps;
	int targetFps = 60;
	int frames;
};