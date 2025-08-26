#pragma once
#include "FileOutputStream.h"
#include "OutputDecorator.h"

class BufferedOutputStream :
	public OutputDecorator
{
	char m_Buffer[512]{} ;
public:


	BufferedOutputStream(OutputStream* pOs)
		: OutputDecorator{pOs} {
	}

	void Write(const std::string& text) override;
	void Close() override;
};

