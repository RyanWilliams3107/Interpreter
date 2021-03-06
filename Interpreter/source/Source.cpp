#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Node.h"
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
		auto [tokens, error] = lexer.GenerateTokens();
	
		for (auto& v : tokens)
		{
			std::visit([](auto&& arg) {
				std::cout << arg << " ";
				}, v);
		}
		std::cout << std::endl;

		Parser parser(tokens);

		NumberNode<IntegerToken> Left = NumberNode<IntegerToken>(IntegerToken(TOK_INTEGER, 12, Position(), Position()));
		NumberNode<FloatToken> Right = NumberNode<FloatToken>(FloatToken(TOK_FLOAT, 1.23, Position(), Position()));
		OperatorToken OpTok = OperatorToken(Operator(TOK_PLUS, Position()));

		std::cout << Left << std::endl;
		std::cout << Right << std::endl;

		BinaryOperationNode<IntegerToken, FloatToken> binopnode = BinaryOperationNode<IntegerToken, FloatToken>(Left, OpTok, Right);
		std::cout << binopnode << std::endl;

		NumberNode<FloatToken> ft = NumberNode<FloatToken>(FloatToken(TOK_FLOAT, 3.5f, Position(), Position()));
		UnaryOperationNode<NumberNode<FloatToken>> uon = UnaryOperationNode<NumberNode<FloatToken>>(OperatorToken(Operator(TOK_MINUS, Position())), ft);
		std::cout << uon << std::endl;
	}
	std::cin.get();
	return 0;
}