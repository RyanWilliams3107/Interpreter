#include "Token.h"
#include "Lexer.h"
#include<vector>
#include<variant>

int main()
{
	std::cout << "(3.0 + 4) + (5 * 5.5) - (15/5) - 6" << std::endl;
	Lexer l("<stdin>", "(3.0 + 4) + (5 * 5.5) - (15 / 5) - 6");
	std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> generatedTokens = l.GenerateTokens();
	std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens = generatedTokens.first;
	bool error = generatedTokens.second;

	for (auto& v : tokens)
	{
		
		std::visit([](auto&& arg) { 
			std::cout << arg.GetTokenType() << ": " << arg.GetTokenValue() <<  " "; 
			}, v);
		

	}
	std::cin.get();
	return 0;
}