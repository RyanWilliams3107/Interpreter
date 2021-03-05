#ifndef _OPERATORTOKEN_CPP
#define _OPERATORTOKEN_CPP

#include "Position.h"
#include "Operator.h"
#include <iostream>

class OperatorToken
{

public:
	OperatorToken();
	OperatorToken(Operator op);
	~OperatorToken();
	std::string GetTokenType();
	std::string GetTokenValue();
	Position GetStartPosition();
	Position GetEndPosition();
	void SetTokenType(const std::string& tokType);
	void SetStartPosition(Position newPos);
	void SetEndPosition(Position newPos);
	OperatorToken Copy();
private:
	std::string m_TokenType;
	std::string m_TokenValue = "none";
	Position m_StartPosition;
	Position m_EndPosition;
};
#endif