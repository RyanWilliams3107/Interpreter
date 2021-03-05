#ifndef _FLOATTOKEN_CPP
#define _FLOATTOKEN_CPP

#include "Position.h"
#include <iostream>

class FloatToken
{
public:
	FloatToken();
	FloatToken(const std::string& tokenType);
	FloatToken(const std::string& tokenType, float Value);	
	FloatToken(const std::string& tokenType, Position startPos);
	FloatToken(const std::string& tokenType, float Value, Position startPos);
	FloatToken(const std::string& tokenType, float value, Position startPos, Position endPos);
	~FloatToken();
	std::string GetTokenType() const;
	float GetTokenValue() const;
	Position GetStartPosition() const;
	Position GetEndPosition() const;
	void SetTokenType(const std::string& tokType);
	void SetTokenValue(float tokValue);
	void SetStartPosition(Position newPos);
	void SetEndPosition(Position newPos);
	FloatToken Copy();

	friend std::ostream& operator<<(std::ostream& os, const FloatToken &ft);
private:
	std::string m_TokenType;
	float m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;
};
#endif // !_FLOATTOKEN_CPP
