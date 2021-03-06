#include "OperatorToken.h"

OperatorToken::OperatorToken()
{
}

OperatorToken::OperatorToken(Operator op)
{
	m_TokenType = op.m_OperatorName;
	m_StartPosition = op.m_Position;
	m_EndPosition = op.m_Position.Copy();
}

OperatorToken::~OperatorToken()
{
}

std::string OperatorToken::GetTokenType() const
{
	return m_TokenType;
}


std::string OperatorToken::GetTokenValue() const
{
	return m_TokenValue;
}

Position OperatorToken::GetStartPosition() const
{
	return m_StartPosition;
}

Position OperatorToken::GetEndPosition() const
{
	return m_EndPosition;
}

void OperatorToken::SetTokenType(const std::string& tokType)
{
	m_TokenType = tokType;
}

void OperatorToken::SetStartPosition(Position newPos)
{
	m_StartPosition = newPos;
}

void OperatorToken::SetEndPosition(Position newPos)
{
	m_EndPosition = newPos;
}

OperatorToken OperatorToken::Copy()
{
	return OperatorToken(Operator(m_TokenType, m_StartPosition));
}



std::ostream& operator<<(std::ostream& os, const OperatorToken& ot)
{
	os << ot.GetTokenType() << ", " << ot.GetTokenValue() << ".";
	return os;
}
