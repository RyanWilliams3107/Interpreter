#ifndef _STRINGTOKEN_CPP
#define _STRINGTOKEN_CPP

#include <iostream>
#include "Position.h"

class StringToken
{
public:
	StringToken();
	StringToken(const std::string& tokenType);
	StringToken(const std::string& tokenType, std::string Value);
	StringToken(const std::string& tokenType, Position startPos);
	StringToken(const std::string& tokenType, std::string Value, Position startPos);
	StringToken(const std::string& tokenType, std::string value, Position startPos, Position endPos);
	~StringToken();
	std::string GetTokenType();
	std::string GetTokenValue();
	Position GetStartPosition();
	Position GetEndPosition();
	void SetTokenType(const std::string& tokType);
	void SetTokenValue(const std::string& tokValue);
	void SetStartPosition(Position newPos);
	void SetEndPosition(Position newPos);	
	StringToken Copy();
private:
	std::string m_TokenType;
	std::string m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;	
};
#endif