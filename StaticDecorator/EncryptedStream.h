#pragma once
#include "FileOutputStream.h"
template<typename T>
class EncryptedStream :
	public T
{
public:
	template<typename...Args>
	EncryptedStream(Args&&...args)
		: T{ std::forward<Args>(args)... } {
	}

	void Write(const std::string& text) {
		std::string encrypted{};
		encrypted.resize(text.size());
		std::transform(text.begin(), text.end(), encrypted.begin(), [](char ch) {
			return ch + 5;
		});
		T::Write(encrypted);
	}

	void Close() {
		T::Close();
	}
};

