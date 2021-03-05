#include "IntegerToken.h"

IntegerToken::IntegerToken()
{
	m_TokenValue = 0;
}

IntegerToken::IntegerToken(const std::string& tokenType)
{
	m_TokenType = tokenType;
}

IntegerToken::IntegerToken(const std::string& tokenType, int Value)
{
	m_TokenType = tokenType;
	m_TokenValue = Value;
}

IntegerToken::IntegerToken(const std::string& tokenType, Position startPos)
{
	m_TokenType = tokenType;
	m_StartPosition = startPos.Copy();
	m_EndPosition = startPos.Copy();
}

IntegerToken::IntegerToken(const std::string& tokenType, int Value, Position startPos)
{
	m_TokenType = tokenType;
	m_TokenValue = Value;
	m_StartPosition = startPos.Copy();
	m_EndPosition = startPos.Copy();
}
IntegerToken::IntegerToken(const std::string& tokenType, int value, Position startPos, Position endPos)
{
	m_TokenType = tokenType;
	m_TokenValue = value;
	m_StartPosition = startPos.Copy();
	m_EndPosition = endPos.Copy();
}

IntegerToken::~IntegerToken()
{
}

std::string IntegerToken::GetTokenType()
{
	return m_TokenType;
}

int IntegerToken::GetTokenValue()
{
	return m_TokenValue;
}

Position IntegerToken::GetStartPosition()
{
	return m_StartPosition;
}

Position IntegerToken::GetEndPosition()
{
	return m_EndPosition;
}

void IntegerToken::SetTokenType(std::string tokType)
{
	m_TokenType = tokType;
}

void IntegerToken::SetTokenValue(int tokValue)
{
	m_TokenValue = tokValue;
}

void IntegerToken::SetStartPosition(Position newPos)
{
	m_StartPosition = newPos;
}

void IntegerToken::SetEndPosition(Position newPos)
{
	m_EndPosition = newPos;
}

IntegerToken IntegerToken::Copy()
{
	return IntegerToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
}
