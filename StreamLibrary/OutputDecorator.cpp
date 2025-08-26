#include "OutputDecorator.h"

void OutputDecorator::Write(const std::string& text) {
	m_pOS->Write(text) ;
}

void OutputDecorator::Close() {
	m_pOS->Close() ;
}
