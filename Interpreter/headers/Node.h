#ifndef _NODE_CPP
#define _NODE_CPP
#include "Token.h"

template<class T>
class NumberNode
{
private:
	T m_Token;
	Position m_Start;
	Position m_End;
public:
	NumberNode<T>()
	{
	
	}
	NumberNode<T>(T tok)
	{
		m_Token = tok;
		m_Start = tok.GetStartPosition();
		m_End = tok.GetEndPosition();
	}
	T GetToken() const { return m_Token; }
	Position GetStart() const { return m_Start;  }
	Position GetEnd() const { return m_End;  }
	void SetToken(T tok) { m_Token = tok; }
	void SetStart(Position New) { m_Start = New; }
	void SetEnd(Position New) { m_End = New; }

	friend std::ostream& operator<<(const std::ostream& os, const NumberNode<T>& node);
};

template<typename Left, typename Right>
class BinaryOperationNode
{
private:
	NumberNode<Left> m_Left;
	NumberNode<Right> m_Right;
	OperatorToken m_OpTok;
	Position m_Start;
	Position m_End;
public:
	BinaryOperationNode<Left, Right>(NumberNode<Left> Left, OperatorToken OpTok, NumberNode<Right> Right)
	{
		m_Left = Left;
		m_OpTok = OpTok;
		m_Right = Right;
		m_Start = Left.GetStart();
		m_End = Right.GetEnd();
	}

	void SetLeft(NumberNode<Left> New) { m_Left = New; }
	void SetRight(NumberNode<Right> New) { m_Right = New; }
	void SetToken(OperatorToken tok) { m_OpTok = tok; }
	void SetStart(Position New) { m_Start = New; }
	void SetEnd(Position New) { m_End = New; }

	NumberNode<Left> GetLeft() const { return m_Left; }
	NumberNode<Right> GetRight() const { return m_Right;  }
	OperatorToken GetToken() const { return m_OpTok;  }
	Position GetStart() const { return m_Start; }
	Position GetEnd() const { return m_End; }

	friend std::ostream& operator<<(const std::ostream& os, const BinaryOperationNode<Left, Right>& node);
};

template <typename T>
class UnaryOperationToken
{
public:
	OperatorToken m_Token;
	T m_Node;
	Position m_Start;
	Position m_End;
private:
	UnaryOperationToken<T>(OperatorToken optok, T node)
	{
		m_Token = optok;
		m_Node = node;
		m_Start = optok.GetStartPosition();
		m_End = node.GetEnd();
	}
};



template <typename T>
std::ostream& operator<<(std::ostream& os, const NumberNode<T>& node)
{
	os << node.GetToken();
	return os;
}


template <typename Left, typename Right>
std::ostream& operator<<(std::ostream& os, const BinaryOperationNode<Left, Right>& node)
{
	os << node.GetLeft() << " " << node.GetToken() << " " << node.GetRight();
	return os;
}
#endif;