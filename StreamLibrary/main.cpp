
#include <iostream>

#include "BufferedInputStream.h"
#include "BufferedOutputStream.h"
#include "CompressedOutputStream.h"
#include "DecompressedInputStream.h"
#include "DecryptedStream.h"
#include "EncryptedStream.h"
#include "FileInputStream.h"
#include "FileOutputStream.h"

// Only one of them
#define ENABLE_MIX_USAGE
//#define ENABLE_SINGLE_USAGE

void BufferedRead() {
	FileInputStream fs{ "test.txt" };
	BufferedInputStream input{ &fs };
	std::string text{};
	while (input.Read(text)) {
		std::cout << text << std::endl;
	}
}
void BufferedWrite() {
	FileOutputStream fs{ "test.txt" };
	BufferedOutputStream output{ &fs };
	output.Write("First line");
	output.Write("Second line");
	output.Write("Third line");
}

void Encrypt() {
	FileOutputStream fs{ "encryption.txt" };
	EncryptedStream output{ &fs };
	output.Write("First line");
	output.Write("Second line");
	output.Write("Third line");
}
void Decrypt() {
	FileInputStream fs{ "encryption.txt" };
	DecryptedStream input{ &fs };
	std::string text{};
	while (input.Read(text)) {
		std::cout << text << std::endl;
	}
}

void Operate(OutputStream* pOS) {
	pOS->Write("Some text");  // Polymorphysm pure
	pOS->Close();
}

void Compress() {
	FileOutputStream fs{ "compression.txt" };
	CompressedOutputStream output{ &fs };
	Operate(&output);
	/*output.Write("First line") ;
	output.Write("Second line") ;
	output.Write("Third line") ;*/
}
void Decompress() {
	FileInputStream fs{ "compression.txt" };
	DecompressedInputStream input{ &fs };
	std::string text{};
	while (input.Read(text)) {
		std::cout << text << std::endl;
	}
}


int main() {
#ifdef ENABLE_MIX_USAGE
	FileOutputStream fs{ "mix.txt" };
	BufferedOutputStream bs{ &fs };
	CompressedOutputStream cs{ &bs };
	EncryptedStream es{ &cs };

	es.Write("First line");
	es.Write("Second line");
	es.Write("Third line");
	es.Close();

	FileInputStream fsInput{ "mix.txt" };
	BufferedInputStream bsInput{ &fsInput };
	DecompressedInputStream decInput{ &bsInput };
	DecryptedStream dcrInput{ &decInput };
	std::string text{};
	dcrInput.Read(text);
	std::cout << text << std::endl;
	dcrInput.Read(text);
	std::cout << text << std::endl;
	dcrInput.Read(text);
	std::cout << text << std::endl;
	dcrInput.Close();
#elif defined ENABLE_SINGLE_USAGE
	BufferedWrite();
	BufferedRead();

	Encrypt();
	Decrypt();

	Compress();
	Decompress();
#endif
}

