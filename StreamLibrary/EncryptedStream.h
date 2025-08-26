#pragma once
#include "FileOutputStream.h"
#include "OutputDecorator.h"

class EncryptedStream :
	public OutputDecorator
{
public:

	EncryptedStream(OutputStream* pOs)
		: OutputDecorator{pOs} {
	}


	void Write(const std::string& text) override;
	void Close() override;
};

