#pragma once
#include "FileOutputStream.h"
#include "comp_util.h"
template<typename T>
class CompressedOutputStream : public T
{
public:
	template<typename...Args>
	CompressedOutputStream(Args&&...args)
		: T{ std::forward<Args>(args)... } {
	}

	void Write(const std::string& text) {
		auto cmpText = Compress(text);
		T::Write(cmpText);
	}

	void Close() {
		T::Close();
	}
};

