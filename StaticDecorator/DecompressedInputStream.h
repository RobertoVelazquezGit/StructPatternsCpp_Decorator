#pragma once
#include "FileInputStream.h"
template<typename T>
class DecompressedInputStream : public T
{
public:
	template<typename...Args>
	DecompressedInputStream(Args&&...args)
		: T{ std::forward<Args>(args)... } {
	}


	bool Read(std::string& text) {
		std::string compText{};
		auto result = T::Read(compText);
		text = Decompress(compText);
		return result;
	}
	void Close() {
		T::Close();
	}
};

