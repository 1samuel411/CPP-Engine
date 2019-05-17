#pragma once

#include "../Headers.h"
#include "../Components/Component.h"
#include "../Components/Transform/Transform.h"

#include <list>

using namespace std;


class Object
{
public:
	Transform* transform;
	Object();
	void Start();
	void Update();
	void Render();
	void AddComponent(Component*);
	template <typename T> T* GetComponent();


private:
	list<Component*> components;

};

template <class T>
T* Object::GetComponent()
{
	T* result = nullptr;
	for (list<Component*>::iterator it = components.begin(); it != components.end(); it++)
	{
		result = dynamic_cast<T*>(*it);
		if (result)
			break;
	}
	return result;
}