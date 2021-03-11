#ifndef _PARSERESULT_CPP
#define _PARSERESULT_CPP

#include "Error.h"
#include "Node.h"
#include <vector>
#include<variant> 
#include <any>
class ParseResult
{
public:
	ParseResult();
	std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>> Register(const ParseResult& res);
	ParseResult Success(const std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>>& node);
	ParseResult Failure(const std::variant<Error, InvalidSyntaxError, RuntimeError, IllegalCharacterError>& error);
	std::variant<Error, InvalidSyntaxError, RuntimeError, IllegalCharacterError>* GetError() const { return m_Error; }
	std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>>* GetNode() const { return m_Node; }


	
private:
	std::variant<Error, InvalidSyntaxError, RuntimeError, IllegalCharacterError>* m_Error = nullptr;
	std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>>* m_Node = nullptr;
};
#endif

