#include "Bird.h"
#include "../../Engine/Objects/Object.h"

Rigidbody* rigidbody;

void Bird::Start()
{
	rigidbody = object->GetComponent<Rigidbody>();
	rigidbody->kinematic = false;
}

void Bird::Update()
{
	if (Input::GetKeyDown(GLFW_KEY_SPACE))
	{
		Jump();
	}
}

void Bird::Render()
{
}

void Bird::Jump()
{
	rigidbody->kinematic = true;

	Vector2 force = Vector2();
	force.y = jumpForce;
	rigidbody->SetVelocity(force);
}