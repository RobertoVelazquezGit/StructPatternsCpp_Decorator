#include <iostream>

#include "DecryptedStream.h"
#include "EncryptedStream.h"
#include "FileOutputStream.h"
#include "FileInputStream.h"
#include "CompressedOutputStream.h"
#include "DecompressedInputStream.h"
#include "BufferedInputStream.h"
#include "BufferedOutputStream.h"

// Only one of them
#define ENABLE_COMPRESS_ENCRYPT
//#define ENABLE_COMPRESS_ENCRYPT_BUFFER

void Read() {
	DecompressedInputStream<DecryptedStream<FileInputStream>> in{"test.txt"} ;
	std::string text{} ;
	while(in.Read(text)) {
		std::cout << text << std::endl ;
	}
}
void Write() {
	CompressedOutputStream<EncryptedStream<FileOutputStream>> out{"test.txt"} ;
	out.Write("Using mixin to implement static decorator") ;
	out.Write("Decorators are chosen at compile-time") ;
}

void ReadB() {
	DecompressedInputStream<DecryptedStream<BufferedInputStream<FileInputStream>>> in{ "testB.txt" };
	std::string text{};
	while (in.Read(text)) {
		std::cout << text << std::endl;
	}
}
void WriteB() {
	CompressedOutputStream<EncryptedStream<BufferedOutputStream<FileOutputStream>>> out{ "testB.txt" };
	out.Write("Using mixin to implement static decorator B");
	out.Write("Decorators are chosen at compile-time B");
}

int main() {
#ifdef ENABLE_COMPRESS_ENCRYPT
	Write() ;
	Read() ;
#elif defined ENABLE_COMPRESS_ENCRYPT_BUFFER
	WriteB();
	ReadB();
#endif
}
