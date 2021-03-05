#ifndef _ILLEGALCHARACTERERROR_CPP
#define _ILLEGALCHARACTERERROR_CPP
#include <iostream>
#include "Position.h"
class IllegalCharacterError
{
public:
	IllegalCharacterError(Position Start, Position End, const std::string& Details);
	std::string ErrorAsString() const;
private:
	Position m_StartPosition;
	Position m_EndPosition;
	std::string m_ErrorName;
	std::string m_ErrorDetails;
};
#endif

