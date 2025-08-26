#pragma once
#include "FileOutputStream.h"
template<typename T>
class BufferedOutputStream :
	public T
{
	char m_Buffer[512]{};
public:

	template<typename...Args>
	BufferedOutputStream(Args&&...args)  // Universal reference
		: T{ std::forward<Args>(args)... } {  // Perfect forwarding
	}


	void Write(const std::string& text) {
		std::cout << "Buffered Write\n";
		T::Write(text);
	}

	void Close() {
		T::Close();
	}
};

