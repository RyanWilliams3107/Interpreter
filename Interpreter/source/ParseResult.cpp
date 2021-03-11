#include "ParseResult.h"

ParseResult::ParseResult()
{
}

std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>> ParseResult::Register(const ParseResult& res)
{
	if (res.GetError() != nullptr)
	{
		m_Error = res.GetError();
	}
	return *res.GetNode();
}

ParseResult ParseResult::Success(const std::variant<NumberNode<std::any>, BinaryOperationNode<std::any, std::any>, UnaryOperationNode<std::any>>& node)
{
	*m_Node = node;
	return *this;
}

ParseResult ParseResult::Failure(const std::variant<Error, InvalidSyntaxError, RuntimeError, IllegalCharacterError>& error)
{
	*m_Error = error;
	return *this;
}
