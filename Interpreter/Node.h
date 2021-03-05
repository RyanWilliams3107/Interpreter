#ifndef _NODE_CPP
#define _NODE_CPP
#include "Token.h"
template<class T>
class NumberNode
{
private:
	T m_Token;
public:
	NumberNode<T>(Token<T> tok)
	{
		m_Token = tok;
	}
	Token<T> GetToken()
	{
		return m_Token;
	}
	void SetToken(Token<T> tok)
	{
		m_Token = tok;
	}
};

template<class T>
class BinaryOperationNode
{
private:
	NumberNode m_Left;
	NumberNode m_Right;
	T m_OpTok;
public:
	BinaryOperationNode<T>(NumberNode Left, Token OpTok, NumberNode Right)
	{
		m_Left = Left;
		m_OpTok = OpTok;
		m_Right = Right;
	}

};
#endif;