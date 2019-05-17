#pragma once

#include "../../Headers.h"
#include "../Component.h"
#include "../../Structures/Structures.h"

class Rigidbody : public Component
{
public:
	void Start();
	void Update();
	void Render();
	void AddForce(Vector2);
	void SetVelocity(Vector2);
	float gravity = -9.81f;
	bool kinematic = true;

private:
	Vector2 velocity;

};