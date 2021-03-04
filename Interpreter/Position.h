#ifndef _POSITION_CPP
#define _POSITION_CPP
#include <iostream>
class Position
{
private:
	int m_index;
	int m_lineNumber;
	int m_columnNumber;
	std::string m_fileName;
	std::string m_fileContents;
public:
	Position();
	Position(int index, int lineNumber, int columnNumber, std::string fileName, std::string fileContents);
	~Position() {}
	Position Copy();
	void Advance(char current = NULL);
	int GetIndex();
	bool operator==(const Position& other) const;

};

#endif


