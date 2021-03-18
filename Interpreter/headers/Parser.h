#ifndef _PARSER_CPP
#define _PARSER_CPP
#include "Token.h"
#include "ParseResult.h"
#include <vector>
#include <iostream>
#include <variant>
class Parser
{
private:
	std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> m_Tokens;
	int m_TokenIndex = -1;
	std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> m_currentToken;
	enum TokenType
	{
		INTEGER = 0,
		FLOAT = 1,
		OPERATOR = 2,
		STRING = 3,
		NONE = 4
	};
public:
	Parser(std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens);
	void Advance();
	ParseResult Parse();
	ParseResult Factor();
	ParseResult BinaryOperation();
	ParseResult Term();
	ParseResult Expression();
	TokenType IsCurrentTokenIntToken();
	TokenType IsCurrentTokenFloatToken();
	TokenType IsCurrentTokenOpToken();
	TokenType IsCurrentTokenStrToken();
};
#endif

