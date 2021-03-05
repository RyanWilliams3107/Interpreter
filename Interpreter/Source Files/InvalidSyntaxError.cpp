#include "InvalidSyntaxError.h"

InvalidSyntaxError::InvalidSyntaxError(Position Start, Position End, const std::string& Details)
{
	m_StartPosition = Start.Copy();
	m_EndPosition = End.Copy();
	m_ErrorName = "Invalid Syntax Error";
	m_ErrorDetails = Details;
}

std::string InvalidSyntaxError::ErrorAsString() const
{
	return std::string();
}
