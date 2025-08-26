#pragma once
#include "Component.h"
class Decorator :
	public Component
{
	Component* m_ptr{};

public:
	Decorator(Component* ptr)
		: m_ptr{ ptr } {
	}

	void Operation() override;
};
