#include "Position.h"

Position::Position()
{
	m_index = -5;
	m_columnNumber = -5;
	m_lineNumber = -5;
}

Position::Position(int index, int lineNumber, int columnNumber, std::string fileName, std::string fileContents)
{
	m_index = index;
	m_lineNumber = lineNumber;
	m_columnNumber = columnNumber;
	m_fileName = fileName;
	m_fileContents = fileContents;
}

Position Position::Copy()
{
	return Position(m_index, m_lineNumber, m_columnNumber, m_fileName, m_fileContents);
}

void Position::Advance(char current)
{
	m_index++;
	m_columnNumber++;
	if (current == '\n')
	{
		m_lineNumber++;
		m_columnNumber = 0;
	}
}

int Position::GetIndex()
{
	return m_index;
}

bool Position::operator==(const Position& other) const
{
	return (m_index == other.m_index) && (m_lineNumber == other.m_lineNumber) && (m_columnNumber == other.m_columnNumber) && (m_fileName == other.m_fileName) && (m_fileContents == other.m_fileContents);
}
