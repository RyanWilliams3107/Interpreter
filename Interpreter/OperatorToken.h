#ifndef _OPERATORTOKEN_CPP
#define _OPERATORTOKEN_CPP

#include "Position.h"
#include "Operator.h"
#include <iostream>

class OperatorToken
{
private:
	std::string m_TokenType;
	std::string m_TokenValue = "none";
	Position m_StartPosition;
	Position m_EndPosition;

public:
	OperatorToken()
	{

	}
	OperatorToken(Operator op)
	{
		m_TokenType = op.m_OperatorName;
		m_StartPosition = op.m_Position;
		m_EndPosition = op.m_Position.Copy();
	}

	~OperatorToken() {}

	std::string GetTokenType()
	{
		return m_TokenType;
	}

	std::string GetTokenValue()
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

	void SetStartPosition(Position newPos)
	{
		m_StartPosition = newPos;
	}

	void SetEndPosition(Position newPos)
	{
		m_EndPosition = newPos;
	}

	OperatorToken Copy()
	{
		return OperatorToken(Operator(m_TokenType, m_StartPosition));
	}
};

#endif