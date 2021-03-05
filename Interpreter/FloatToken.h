#ifndef _FLOATTOKEN_CPP
#define _FLOATTOKEN_CPP

#include "Position.h"
#include <iostream>



class FloatToken
{
private:
	std::string m_TokenType;
	float m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;

public:
	FloatToken()
	{
		m_TokenValue = 0.0f;
	}
	FloatToken(const std::string& tokenType)
	{
		m_TokenType = tokenType;
	}
	FloatToken(const std::string& tokenType, float Value)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
	}
	FloatToken(const std::string& tokenType, Position startPos)
	{
		m_TokenType = tokenType;
		m_StartPosition = startPos;
	}
	FloatToken(const std::string& tokenType, float Value, Position startPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = startPos.Copy();
	}
	FloatToken(const std::string& tokenType, float value, Position startPos, Position endPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = endPos.Copy();
	}

	~FloatToken() {}

	std::string GetTokenType()
	{
		return m_TokenType;
	}

	float GetTokenValue()
	{
		return m_TokenValue;
	}

	Position GetStartPosition()
	{
		return m_StartPosition;
	}

	Position GetEndPosition()
	{
		return m_EndPosition;
	}

	void SetTokenType(const std::string& tokType)
	{
		m_TokenType = tokType;
	}

	void SetTokenValue(float tokValue)
	{
		m_TokenValue = tokValue;
	}

	void SetStartPosition(Position newPos)
	{
		m_StartPosition = newPos;
	}

	void SetEndPosition(Position newPos)
	{
		m_EndPosition = newPos;
	}
	FloatToken Copy()
	{
		return FloatToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
	}
};
#endif // !_FLOATTOKEN_CPP
