
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

// Only one of them
//#define ENABLE_CALL_TO_DEC_B_OPERATION
#define ENABLE_CALL_TO_OPERATE_FUNC

void Operate(Component* c) {
	c->Operation();
}
int main() {
	ConcreteComponent component{};
	ConcreteDecoratorA decA{ &component };
	//decA.Operation() ;
	ConcreteDecoratorB decB{ &decA };
#ifdef ENABLE_CALL_TO_DEC_B_OPERATION
	decB.Operation() ;
	decB.OtherOperation() ;
#elif defined ENABLE_CALL_TO_OPERATE_FUNC
	Operate(&decB);
#endif
}

