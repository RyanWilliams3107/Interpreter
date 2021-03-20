#include "Parser.h"

Parser::Parser(std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens)
{
	m_Tokens = tokens;
	Advance();
}

std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> Parser::Advance()
{
	m_TokenIndex++;
	if (m_TokenIndex < (int)m_Tokens.size())
	{
		m_currentToken = m_Tokens[m_TokenIndex];
	}
	return m_currentToken;
}

ParseResult Parser::Parse()
{
	ParseResult result = Expression();

}

ParseResult Parser::Factor()
{
	ParseResult result = ParseResult();
	std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> tempToken = m_currentToken;


	while (m_TokenIndex < (int)m_Tokens.size())
	{

		Parser::TokenType type = ExtractTokenType(tempToken);
		auto [IntToken, FltToken, StrToken, OpToken] = GetToken(type, tempToken);
		switch  (type)
		{
		case Parser::TokenType::INTEGER:
			break;
		case Parser::TokenType::FLOAT:
			break;
		case Parser::TokenType::OPERATOR:
			break;
		case Parser::TokenType::STRING:
			break;
		}
		Advance();
	}
}

ParseResult Parser::BinaryOperation()
{
	return ParseResult();
}

ParseResult Parser::Term()
{
	return ParseResult();
}

ParseResult Parser::Expression()
{
	return ParseResult();
}

Parser::TokenType Parser::ExtractTokenType(std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> token)
{
	TokenType type;

	try
	{
		std::get<IntegerToken>(token);
		type = Parser::TokenType::INTEGER;
		return type;
	}
	catch (const std::bad_variant_access& e) { }
	try
	{
		std::get<FloatToken>(token);
		type = Parser::TokenType::FLOAT;
		return type;
	}
	catch (const std::bad_variant_access& e) {}

	try
	{
		std::get<OperatorToken>(token);
		type = Parser::TokenType::OPERATOR;
		return type;
	}
	catch (const std::bad_variant_access& e) {}

	try
	{
		std::get<StringToken>(token);
		type = Parser::TokenType::STRING;
		return type;
	}
	catch (const std::bad_variant_access& e) {}

	return Parser::TokenType::NONE;
}

std::tuple<IntegerToken, FloatToken, OperatorToken, StringToken> Parser::GetToken(Parser::TokenType type, std::variant<IntegerToken, FloatToken, StringToken, OperatorToken> token)
{
	if (type == Parser::TokenType::INTEGER) {
		IntegerToken intToken = std::get<IntegerToken>(token);
		return { intToken, FloatToken(), OperatorToken(), StringToken() };
	}
	else if (type == Parser::TokenType::FLOAT) {
		FloatToken floatToken = std::get<FloatToken>(token);
		return { IntegerToken(), floatToken, OperatorToken(), StringToken() };
	}
	else if (type == Parser::TokenType::OPERATOR) {
		OperatorToken opToken = std::get<OperatorToken>(token);
		return { IntegerToken(), FloatToken(), opToken, StringToken() };	
	}
	else {
		StringToken strToken = std::get<StringToken>(token);
		return { IntegerToken(), FloatToken(), OperatorToken(), strToken };
	}
	return std::tuple<IntegerToken, FloatToken, OperatorToken, StringToken>();
}


