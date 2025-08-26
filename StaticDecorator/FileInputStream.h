#pragma once
#include <fstream>
class FileInputStream 
{
	std::ifstream m_Reader ;
public:
	FileInputStream() = default ;
	FileInputStream(const std::string &fileName) ;
	bool Read(std::string& text) ;
	void Close() ;
};

