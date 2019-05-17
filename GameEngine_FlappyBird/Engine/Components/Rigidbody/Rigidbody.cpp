#include "Rigidbody.h"
#include "../../Objects/Object.h"

void Rigidbody::Start()
{
}

void Rigidbody::Update()
{
	if (kinematic == false)
		return;
	velocity.y += gravity * Time::GetDeltaTime();

	object->transform->position.x += velocity.x;
	object->transform->position.y += velocity.y;
}

void Rigidbody::Render()
{

}

void Rigidbody::AddForce(Vector2 force)
{
	velocity.x += force.x * Time::GetDeltaTime();
	velocity.y += force.y * Time::GetDeltaTime();
}

void Rigidbody::SetVelocity(Vector2 vel)
{
	velocity.x = vel.x * Time::GetDeltaTime();
	velocity.y = vel.y * Time::GetDeltaTime();
}