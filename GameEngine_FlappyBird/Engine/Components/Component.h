#pragma once

#include "../Headers.h"

class Object;
class Component
{
public:
	Object* object;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

private:

};