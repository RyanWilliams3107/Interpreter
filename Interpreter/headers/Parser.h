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
	std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> Advance();
	ParseResult Parse();
	ParseResult Factor();
	ParseResult BinaryOperation();
	ParseResult Term();
	ParseResult Expression();
	TokenType ExtractTokenType(std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> token);
	std::tuple<IntegerToken, FloatToken, OperatorToken, StringToken> GetToken(TokenType type, std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> token);
};
#endif

