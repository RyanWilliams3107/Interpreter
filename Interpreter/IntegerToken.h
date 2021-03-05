#ifndef _INTEGERTOKEN_CPP
#define _INTEGERTOKEN_CPP
#include <iostream>
#include "Position.h"


class IntegerToken
{

public:
	IntegerToken();
	IntegerToken(const std::string& tokenType);
	IntegerToken(const std::string& tokenType, int Value);
	IntegerToken(const std::string& tokenType, Position startPos);
	IntegerToken(const std::string& tokenType, int Value, Position startPos);
	IntegerToken(const std::string& tokenType, int value, Position startPos, Position endPos);
	~IntegerToken();
	std::string GetTokenType();
	int GetTokenValue();
	Position GetStartPosition();
	Position GetEndPosition();
	void SetTokenType(std::string tokType);
	void SetTokenValue(int tokValue);
	void SetStartPosition(Position newPos);
	void SetEndPosition(Position newPos);
	IntegerToken Copy();
private:
	std::string m_TokenType;
	int m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;
};

#endif