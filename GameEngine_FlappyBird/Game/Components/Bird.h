#pragma once

#include "../ComponentHeaders.h"
#include "../../Engine/Headers.h"

#include <iostream>

using namespace std;

class Bird : public Component
{

public:
	
	void Update();
	void Render();
};