#include "Lexer.h"
#include "Operator.h"
#include<variant>
#include<vector>
#include <string>

Lexer::Lexer(std::string fileName, std::string text)
{
	m_FileName = fileName;
	m_Text = text;
	m_CurrentPosition = Position(-1, 0, -1, m_FileName, m_Text);
	m_CurrentCharacter = NULL;
	Advance();
}

void Lexer::Advance()
{
	m_CurrentPosition.Advance(m_CurrentCharacter);
	if (m_CurrentPosition.GetIndex() < (int)m_Text.length())
	{
		m_CurrentCharacter = m_Text[m_CurrentPosition.GetIndex()];
	}
	else
	{
		m_CurrentCharacter = NULL;
	}
}

std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> Lexer::GenerateTokens()
{
	std::string digits = DIGITS;
	std::string spaceTab = " \t";
	std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokenVector;
	while (m_CurrentCharacter != NULL)
	{
		if (spaceTab.find(m_CurrentCharacter) != std::string::npos)
		{
			Advance();
		}
		else if (digits.find(m_CurrentCharacter) != std::string::npos)
		{
			std::pair<std::variant<IntegerToken, FloatToken>, bool> tokenT = MakeNumber();
			std::variant<IntegerToken, FloatToken> token = tokenT.first;
			bool integer = tokenT.second;
			
			if (integer) 
			{
				IntegerToken intTokenToPush = std::visit([](auto&& token) -> IntegerToken { 
					return IntegerToken(token.GetTokenType(), (int)token.GetTokenValue(), token.GetStartPosition(), token.GetEndPosition()); }, token);
				tokenVector.push_back(intTokenToPush);
			}
			else
			{
				FloatToken floatTokenToPush = std::visit([](auto&& token) -> FloatToken { 
					return FloatToken(token.GetTokenType(), (float)token.GetTokenValue(), token.GetStartPosition(), token.GetEndPosition()); 
					}, token);
				tokenVector.push_back(floatTokenToPush);
			}
		}
		else if (m_CurrentCharacter == '+')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_PLUS, m_CurrentPosition)));
			Advance();
		}
		else if (m_CurrentCharacter == '-')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_MINUS, m_CurrentPosition)));
			Advance();
		}
		else if (m_CurrentCharacter == '*')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_MULTIPLY, m_CurrentPosition)));
			Advance();
		}
		else if (m_CurrentCharacter == '/')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_DIVIDE, m_CurrentPosition)));
			Advance();
		}
		else if (m_CurrentCharacter == '(')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_LEFTPAREN, m_CurrentPosition)));
			Advance();
		}
		else if (m_CurrentCharacter == ')')
		{
			tokenVector.push_back(OperatorToken(Operator(TOK_RIGHTPAREN, m_CurrentPosition)));
			Advance();
		}
		else
		{
			std::cout << m_CurrentCharacter << std::endl;
			Advance();
		}
	}

	return std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> { tokenVector, false };
}

std::pair<std::variant<IntegerToken, FloatToken>, bool> Lexer::MakeNumber()
{
	std::string numberAsString = "";
	int dotCount = 0;
	Position startPos = m_CurrentPosition.Copy();
	std::string digitsPlusDot = "0123456789.";

	while ((m_CurrentCharacter != NULL) && (digitsPlusDot.find(m_CurrentCharacter) != std::string::npos))
	{
		if (m_CurrentCharacter == '.')
		{
			if (dotCount == 1)
			{
				break;
			}
			dotCount++;
			numberAsString += '.';
		}
		else
		{
			numberAsString += m_CurrentCharacter;
		}
		Advance();

	}

	

	if (dotCount == 0)
	{
		return std::pair<IntegerToken, bool> { IntegerToken(TOK_INTEGER, std::stoi(numberAsString), startPos, m_CurrentPosition), true };
	}
	else
	{
		return std::pair<FloatToken, bool>  { FloatToken(TOK_FLOAT, std::stof(numberAsString), startPos, m_CurrentPosition), false };
	}
}
