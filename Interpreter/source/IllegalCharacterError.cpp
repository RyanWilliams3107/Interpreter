#include "IllegalCharacterError.h"

IllegalCharacterError::IllegalCharacterError(Position Start, Position End, const std::string& Details)
{
	m_StartPosition = Start.Copy();
	m_EndPosition = End.Copy();
	m_ErrorName = "Illegal Character Error";
	m_ErrorDetails = Details;
}

std::string IllegalCharacterError::ErrorAsString() const
{
	return std::string();
}
