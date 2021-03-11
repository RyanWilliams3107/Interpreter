#ifndef _ERROR_CPP
#define _ERROR_CPP

#include <iostream>
#include "Position.h"

class Error
{
public:
	Error(Position Start, Position End, const std::string& Name, const std::string& Details);
	std::string ErrorAsString() const;
private:
	Position m_StartPosition;
	Position m_EndPosition;
	std::string m_ErrorName;
	std::string m_ErrorDetails;
};

#include "RuntimeError.h"
#include "InvalidSyntaxError.h"
#include "IllegalCharacterError.h"

#endif // !_ERROR_CPP



