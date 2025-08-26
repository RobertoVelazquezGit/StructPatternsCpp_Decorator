#include "InputDecorator.h"

bool InputDecorator::Read(std::string& text) {
	return m_pIS->Read(text) ;
}

void InputDecorator::Close() {
	m_pIS->Close() ;
}
