#include "ConcreteDecoratorB.h"

#include <iostream>

void ConcreteDecoratorB::OtherOperation() {
	std::cout << "Supporting operation\n";
}

void ConcreteDecoratorB::Operation() {
	std::cout << "[ConcreteDecoratorB] Operation invoked\n";
	Decorator::Operation();
}
