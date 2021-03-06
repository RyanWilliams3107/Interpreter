#ifndef _RUNTIMEERROR_CPP
#define _RUNTIMEERROR_CPP
#include <iostream>
#include "Position.h"
class RuntimeError
{
public:
	RuntimeError(Position Start, Position End, const std::string& Details);
	std::string ErrorAsString();
private:
	Position m_StartPosition;
	Position m_EndPosition;
	std::string m_ErrorName;
	std::string m_ErrorDetails;
};
#endif

