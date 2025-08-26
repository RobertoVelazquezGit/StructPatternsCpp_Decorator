#pragma once
#include <fstream>
class FileOutputStream 
{
	std::ofstream m_Writer{} ;
public:
	FileOutputStream() = default ;
	FileOutputStream(const std::string &fileName) ;
	void Write(const std::string& text) ;
	void Close() ;
};

