#pragma once
#include "InputStream.h"
class InputDecorator :
	public InputStream
{
	InputStream *m_pIS{} ;

public:
	InputDecorator(InputStream* pIs)
		: m_pIS{pIs} {
	}

	bool Read(std::string& text) override = 0;
	void Close() override = 0;
};

