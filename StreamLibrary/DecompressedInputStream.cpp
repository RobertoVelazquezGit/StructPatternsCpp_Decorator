#include "DecompressedInputStream.h"

#include "comp_util.h"

bool DecompressedInputStream::Read(std::string& text) {
	std::string compText{} ;
	auto result = InputDecorator::Read(compText) ;
	text = Decompress(compText);
	return result ;
}

void DecompressedInputStream::Close() {
	InputDecorator::Close() ;
}
