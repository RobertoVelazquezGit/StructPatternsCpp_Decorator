#pragma once
#include <string>
extern "C" int unishox1_compress(const char *in, int len, char *out);
extern "C" int unishox1_decompress(const char *in, int len, char *out);

inline std::string Compress(const std::string &source) {
	char buffer[1024]{} ;
	unishox1_compress(source.c_str(), source.size(), buffer) ;
	return {buffer} ;
}
inline std::string Decompress(const std::string &source) {
	char buffer[1024]{} ;
	unishox1_decompress(source.c_str(), source.size(), buffer) ;
	return {buffer} ;
}