#include "Lexer.h"
#include "Operator.h"
#include<variant>
#include<vector>
#include <string>

Lexer::Lexer(std::string fileName, const std::string& text)
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
			auto [token, integer] = MakeNumber();
		
			if (integer) 
			{	
				tokenVector.emplace_back(std::get<IntegerToken>(token));
			}
			else
			{
				tokenVector.emplace_back(std::get<FloatToken>(token));
			}
		}
		else if (m_CurrentCharacter == '+')
		{
			tokenVector.emplace_back(Operator(TOK_PLUS, m_CurrentPosition));
			Advance();
		}
		else if (m_CurrentCharacter == '-')
		{
			tokenVector.emplace_back(Operator(TOK_MINUS, m_CurrentPosition));
			Advance();
		}
		else if (m_CurrentCharacter == '*')
		{
			tokenVector.emplace_back(Operator(TOK_MULTIPLY, m_CurrentPosition));
			Advance();
		}
		else if (m_CurrentCharacter == '/')
		{
			tokenVector.emplace_back(Operator(TOK_DIVIDE, m_CurrentPosition));
			Advance();
		}
		else if (m_CurrentCharacter == '(')
		{
			tokenVector.emplace_back(Operator(TOK_LEFTPAREN, m_CurrentPosition));
			Advance();
		}
		else if (m_CurrentCharacter == ')')
		{
			tokenVector.emplace_back(Operator(TOK_RIGHTPAREN, m_CurrentPosition));
			Advance();
		}
		else
		{
			std::cout << m_CurrentCharacter << std::endl;
			Advance();
		}
	}

	tokenVector.emplace_back(Operator(TOK_EOF, m_CurrentPosition));
	return std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> { tokenVector, false };
}

std::pair<std::variant<IntegerToken, FloatToken>, bool> Lexer::MakeNumber()
{
	std::string numberAsString = "";
	int dotCount = 0;
	Position startPos = m_CurrentPosition.Copy();


	while ((m_CurrentCharacter != NULL) && (DIGITSPLUSDOT.find(m_CurrentCharacter) != std::string::npos))
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
		return { IntegerToken(TOK_INTEGER, std::stoi(numberAsString), startPos, m_CurrentPosition), true };
	}
	else
	{
		return { FloatToken(TOK_FLOAT, std::stof(numberAsString), startPos, m_CurrentPosition), false };
	}
}
