#pragma once
#include "FileInputStream.h"
#include "InputDecorator.h"

class BufferedInputStream :
	public InputDecorator
{
public:

	BufferedInputStream(InputStream* pIs)
		: InputDecorator{pIs} {
	}

private:
	char m_Buffer[512]{} ;
public:
	bool Read(std::string& text) override;
	void Close() override;
};

