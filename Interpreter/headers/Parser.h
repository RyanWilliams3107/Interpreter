#ifndef _PARSER_CPP
#define _PARSER_CPP
#include "Token.h"
#include <vector>
#include <iostream>
#include <variant>
class Parser
{
private:
	std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> m_Tokens;
	int m_TokenIndex = -1;
	std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> m_currentToken;
public:
	Parser(std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens);
	void Advance();

};
#endif

