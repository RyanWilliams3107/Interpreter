#include "Parser.h"

Parser::Parser(std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens)
{
	m_Tokens = tokens;
	Advance();
}

void Parser::Advance()
{
	m_TokenIndex++;
	if (m_TokenIndex < m_Tokens.size())
	{
		m_currentToken = m_Tokens[m_TokenIndex];
	}
}
