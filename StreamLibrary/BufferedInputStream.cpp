#include "BufferedInputStream.h"

#include <iostream>

bool BufferedInputStream::Read(std::string& text) {
	auto result = InputDecorator::Read(text) ;
	std::cout << "Buffered Read\n" ;
	return result ;
}

void BufferedInputStream::Close() {
	InputDecorator::Close() ;
}
