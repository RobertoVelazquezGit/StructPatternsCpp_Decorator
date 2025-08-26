#pragma once
#include <algorithm>
template<typename T>
class DecryptedStream :
	public T
{
public:

	template<typename...Args>
	DecryptedStream(Args&&...args)
		: T{ std::forward<Args>(args)... } {
	}

	bool Read(std::string& text)  {
		std::string encrypted{};
		const auto result = T::Read(encrypted);
		if (!encrypted.empty()) {
			text.resize(encrypted.size());
			std::transform(encrypted.begin(), encrypted.end(), text.begin(), [](char ch) {
				return ch - 5;
			});
		}
		return result;
	}
	void Close() {
		T::Close();

	}
};

