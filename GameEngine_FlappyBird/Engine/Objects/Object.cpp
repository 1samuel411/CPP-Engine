#include "Object.h"

Object::Object()
{
	transform = new Transform();
}

void Object::Start()
{
	for (list<Component*>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->Start();
	}
}

void Object::Update()
{
	for (list<Component*>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->Update();
	}
}

void Object::Render()
{
	for (list<Component*>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->Render();
	}
}

void Object::AddComponent(Component* component)
{
	components.insert(components.end(), component);
	component->object = this;
}