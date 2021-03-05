#include "RuntimeError.h"

RuntimeError::RuntimeError(Position Start, Position End, const std::string& Details)
{
	m_StartPosition = Start.Copy();
	m_EndPosition = End.Copy();
	m_ErrorName = "Runtime Error";
	m_ErrorDetails = Details;
}

std::string RuntimeError::ErrorAsString()
{
	return std::string();
}
