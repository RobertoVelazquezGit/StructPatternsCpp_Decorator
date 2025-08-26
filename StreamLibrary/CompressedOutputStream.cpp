#include "CompressedOutputStream.h"

#include "comp_util.h"

void CompressedOutputStream::Write(const std::string& text) {
	auto cmpText = Compress(text) ;
	OutputDecorator::Write(cmpText) ;
}

void CompressedOutputStream::Close() {
	OutputDecorator::Close() ;
}
