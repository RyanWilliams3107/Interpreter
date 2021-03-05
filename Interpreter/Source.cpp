#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include<vector>
#include<variant>
#include<sstream>

int main()
{
	

	std::string statement;
	while (true)
	{
		std::cout << ">>>";
		std::getline(std::cin, statement);
		std::cout << std::endl;
		std::cout << statement << std::endl;

		Lexer lexer("<stdin>", statement);
		std::pair<std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>>, bool> generatedTokens = lexer.GenerateTokens();
		std::vector<std::variant<IntegerToken, FloatToken, StringToken, OperatorToken>> tokens = generatedTokens.first;
		bool error = generatedTokens.second;

		for (auto& v : tokens)
		{
			std::visit([](auto&& arg) {
				std::cout << arg.GetTokenType() << ": " << arg.GetTokenValue() << " ";
				}, v);
		}
		std::cout << std::endl;

		Parser parser(tokens);
	}
	std::cin.get();
	return 0;
}