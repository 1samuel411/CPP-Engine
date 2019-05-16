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
	void Update();
	void Render();
	void AddComponent(Component*);


private:
	list<Component*> components;

};
