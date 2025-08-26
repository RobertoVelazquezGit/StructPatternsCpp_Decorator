#pragma once
#include "OutputStream.h"
#include "FileOutputStream.h"
#include "OutputDecorator.h"

class CompressedOutputStream : public OutputDecorator
{
public:
	CompressedOutputStream(OutputStream* pOs)
		: OutputDecorator{pOs} {
	}

	void Write(const std::string& text) ;
	void Close() ;
};

