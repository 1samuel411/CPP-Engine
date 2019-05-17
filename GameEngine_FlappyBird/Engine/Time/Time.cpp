#include "Time.h"

Time* Time::instance = NULL;

void Time::EndLoop()
{
	long curTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	deltaTime = ((double)curTime - lastFrameTime)/1000;

	frames++;
	if (frames % targetFps == 0)
	{
		fps = 1 / deltaTime;
	}

	lastFrameTime = curTime;
}

void Time::BeginRunning()
{
	instance = this;
	beginTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	fps = 1000 / GetUpdateTime();
}

long Time::GetTimeRunning()
{
	return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() - Time::instance->beginTime;
}

double Time::GetFPS()
{
	return Time::instance->fps;
}

double Time::GetDeltaTime()
{
	return Time::instance->deltaTime;
}

double Time::GetUpdateTime()
{
	return 1.0 / targetFps;
}

void Time::SetTargetFPS(int target)
{
	Time::instance->targetFps = target;
}