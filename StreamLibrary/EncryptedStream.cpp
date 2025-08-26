#include "EncryptedStream.h"

#include <algorithm>

void EncryptedStream::Write(const std::string& text) {
	std::string encrypted{} ;
	encrypted.resize(text.size()) ;
	std::transform(text.begin(), text.end(), encrypted.begin(), [](char ch) {
		return ch + 5 ;
	}) ;
	OutputDecorator::Write(encrypted) ;
}

void EncryptedStream::Close() {
	OutputDecorator::Close() ;
}
