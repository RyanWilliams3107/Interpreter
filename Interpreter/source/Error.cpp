#include "Error.h"
#include "InsertArrowsIntoString.h"
#include <string>

Error::Error(Position Start, Position End, const std::string& Name, const std::string& Details)
{
	m_StartPosition = Start.Copy();
	m_EndPosition = End.Copy();
	m_ErrorName = Name;
	m_ErrorDetails = Details;
}

std::string Error::ErrorAsString() const
{
	std::string result = m_ErrorName + ": " + m_ErrorDetails + "\n";
	result += "File " + m_StartPosition.GetFileName() + ", line " + std::to_string(m_StartPosition.GetLineNumber());

	result += "\n\n" + InsertArrowsIntoString(m_StartPosition.GetFileContents(), m_StartPosition, m_EndPosition);
	return result;
}
