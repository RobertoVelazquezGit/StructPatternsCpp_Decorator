#pragma once
#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorB :
	public Decorator
{
	using Decorator::Decorator;
public:

	void OtherOperation();
	void Operation() override;
};

