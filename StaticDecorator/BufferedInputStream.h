#pragma once
#include <iostream>

#include "FileInputStream.h"
template<typename T>
class BufferedInputStream :
	public T
{
public:
	template<typename...Args>
	BufferedInputStream(Args&&...args)
		: T{ std::forward<Args>(args)... } {
	}


private:
	char m_Buffer[512]{};
public:
	bool Read(std::string& text) {
		auto result = T::Read(text);
		std::cout << "Buffered Read\n";
		return result;
	}

	void Close() {
		T::Close();
	}
};

