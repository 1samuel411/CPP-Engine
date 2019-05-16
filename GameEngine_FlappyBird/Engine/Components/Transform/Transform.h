#pragma once

#include "../../Headers.h"
#include "../Component.h"

#include <iostream>

using namespace std;

class Transform : public Component
{
public:
	Transform();

	void Update();
	void Render();

	Vector2 position;
	float rotation;
	Vector2 scale;

private:


};

