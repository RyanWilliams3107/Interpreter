#ifndef _OPERATOR_CPP
#define _OPERATOR_CPP
#include <iostream>
#include "Position.h"
struct Operator
{
	std::string m_OperatorName;
	Position m_Position;
	Operator()
	{
		m_OperatorName = "default";
		m_Position = Position(-5, -5, -5, "none", "none");

	}
	Operator(std::string opName, Position pos)
	{
		m_OperatorName = opName;
		m_Position = pos;
	}

	std::string GetOperatorName() const { return m_OperatorName; }

	friend std::ostream& operator<<(const std::ostream& os,const Operator& op);
};
#endif