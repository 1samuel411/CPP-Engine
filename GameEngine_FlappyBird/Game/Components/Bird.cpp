#include "Bird.h"
#include "../../Engine/Objects/Object.h"

void Bird::Update()
{
	if (Input::instance->GetKeyUp(GLFW_KEY_SPACE))
	{
		object->transform->position.y += 50;
	}
}

void Bird::Render()
{
}