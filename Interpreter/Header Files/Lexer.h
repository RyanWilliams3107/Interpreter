#ifndef _LEXER_CPP
#define _LEXER_CPP
#include <iostream>
#include <variant>
#include <vector>
#include "Position.h"
#include "Token.h"
class Lexer
{

public:
	Lexer(std::string fileName, const std::string& text);
	void Advance();
	std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> GenerateTokens();
	std::pair<std::variant<IntegerToken, FloatToken>, bool> MakeNumber();
	auto MakeIdentifier();
private:
	std::string m_Text;
	std::string m_FileName;
	Position m_CurrentPosition;
	char m_CurrentCharacter;
};
#endif