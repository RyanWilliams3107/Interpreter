#include "Parser.h"

Parser::Parser(std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens)
{
	m_Tokens = tokens;
	Advance();
}

void Parser::Advance()
{
	m_TokenIndex++;
	if (m_TokenIndex < (int)m_Tokens.size())
	{
		m_currentToken = m_Tokens[m_TokenIndex];
	}
}

ParseResult Parser::Parse()
{
	ParseResult result = Expression();

	while (m_TokenIndex < m_Tokens.size())
	{

		Parser::TokenType IsTypeInteger = IsCurrentTokenIntToken();
		Parser::TokenType IsTypeFloat = IsCurrentTokenFloatToken();
		Parser::TokenType IsTypeOperator = IsCurrentTokenOpToken();
		Parser::TokenType IsTypeString = IsCurrentTokenStrToken();

		if (IsTypeInteger == Parser::TokenType::INTEGER)
		{
			std::cout << IsTypeInteger << " Integer." << std::endl;
		}
		else if (IsTypeFloat == Parser::TokenType::FLOAT)
		{
			std::cout << IsTypeFloat << " Float." << std::endl;
		}
		else if(IsTypeOperator == Parser::TokenType::OPERATOR)
		{
			std::cout << IsTypeOperator << " Operator." << std::endl;
		}
		else 
		{
			std::cout << IsTypeString << " String." << std::endl;
		}
		Advance();
	}


	//std::cout << CurTok << std::endl;
	if (!result.GetError())
	{
	}
	return result;
}

ParseResult Parser::Factor()
{
	return ParseResult();
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

Parser::TokenType Parser::IsCurrentTokenIntToken()
{

	try
	{
		IntegerToken tok = std::get<IntegerToken>(m_currentToken);
		return Parser::TokenType::INTEGER;
	}
	catch (const std::bad_variant_access& e)
	{
		return Parser::TokenType::NONE;
	}	
}

Parser::TokenType Parser::IsCurrentTokenFloatToken()
{
	try
	{
		FloatToken tok = std::get<FloatToken>(m_currentToken);
		return Parser::TokenType::FLOAT;
	}
	catch (const std::bad_variant_access& e)
	{
		return Parser::TokenType::NONE;
	}
}

Parser::TokenType Parser::IsCurrentTokenOpToken()
{
	try
	{
		OperatorToken tok = std::get<OperatorToken>(m_currentToken);
		return Parser::TokenType::OPERATOR;
	}
	catch (const std::bad_variant_access& e)
	{
		return Parser::TokenType::NONE;
	}
}

Parser::TokenType Parser::IsCurrentTokenStrToken()
{
	try
	{
		StringToken tok = std::get<StringToken>(m_currentToken);
		return Parser::TokenType::STRING;
	}
	catch (const std::bad_variant_access& e)
	{
		return Parser::TokenType::NONE;
	}
}
