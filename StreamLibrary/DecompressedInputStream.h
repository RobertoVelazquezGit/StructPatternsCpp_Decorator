#pragma once
#include "FileInputStream.h"
#include "InputDecorator.h"

class DecompressedInputStream : public InputDecorator
{
public:

	DecompressedInputStream(InputStream* pIs)
		: InputDecorator{pIs} {
	}

	bool Read(std::string& text) ;
	void Close() ;
};

