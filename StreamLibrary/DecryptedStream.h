#pragma once
#include "FileInputStream.h"
#include "InputDecorator.h"

class DecryptedStream :
	public InputDecorator
{
public:


	DecryptedStream(InputStream* pIs)
		: InputDecorator{pIs} {
	}

	bool Read(std::string& text) override;
	void Close() override;
};

