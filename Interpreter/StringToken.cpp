#include "StringToken.h"

StringToken::StringToken()
{
}

StringToken::StringToken(const std::string& tokenType)
{
	m_TokenType = tokenType;
}

StringToken::StringToken(const std::string& tokenType, std::string Value)
{
	m_TokenType = tokenType;
	m_TokenValue = Value;
}

StringToken::StringToken(const std::string& tokenType, Position startPos)
{
	m_TokenType = tokenType;
	m_StartPosition = startPos.Copy();
	m_EndPosition = startPos.Copy();
}

StringToken::StringToken(const std::string& tokenType, std::string Value, Position startPos)
{
	m_TokenType = tokenType;
	m_TokenValue = Value;
	m_StartPosition = startPos.Copy();
	m_EndPosition = startPos.Copy();
}

StringToken::StringToken(const std::string& tokenType, std::string value, Position startPos, Position endPos)
{
	m_TokenType = tokenType;
	m_TokenValue = value;
	m_StartPosition = startPos.Copy();
	m_EndPosition = endPos.Copy();
}

StringToken::~StringToken()
{
}

std::string StringToken::GetTokenType() const
{
	return m_TokenType;
}

std::string StringToken::GetTokenValue() const
{
	return m_TokenValue;
}

Position StringToken::GetStartPosition() const
{
	return m_StartPosition;
}

Position StringToken::GetEndPosition() const
{
	return m_EndPosition;
}

void StringToken::SetTokenType(const std::string& tokType)
{
	m_TokenType = tokType;
}

void StringToken::SetTokenValue(const std::string& tokValue)
{
	m_TokenValue = tokValue;
}

void StringToken::SetStartPosition(Position newPos)
{
	m_StartPosition = newPos;
}

void StringToken::SetEndPosition(Position newPos)
{
	m_EndPosition = newPos;
}

StringToken StringToken::Copy()
{
	return StringToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
}

std::ostream& operator<<(std::ostream& os, const StringToken& st)
{
	os << st.GetTokenType() << ", " << st.GetTokenValue() << ".";
	return os;
}
