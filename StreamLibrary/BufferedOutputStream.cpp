#include "BufferedOutputStream.h"

#include <iostream>

void BufferedOutputStream::Write(const std::string& text) {
	std::cout << "Buffered Write\n" ;
	OutputDecorator::Write(text) ;
}

void BufferedOutputStream::Close() {
	OutputDecorator::Close() ;
}
