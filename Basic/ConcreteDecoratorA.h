#pragma once
#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorA :
	public Decorator
{
	using Decorator::Decorator;  // <-- This is public, not private
public:


	void Operation() override;
};

