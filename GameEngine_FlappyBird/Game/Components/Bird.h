#pragma once

#include "../ComponentHeaders.h"
#include "../../Engine/Headers.h"
#include "../../Engine/Structures/Structures.h"
#include "../../Engine/Components/Rigidbody/Rigidbody.h"

#include <iostream>

using namespace std;

class Bird : public Component
{

public:
	void Start();
	void Update();
	void Render();

	void Jump();

private:
	float jumpForce = 350;
};