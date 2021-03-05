#ifndef _INTEGERTOKEN_CPP
#define _INTEGERTOKEN_CPP


class IntegerToken
{
private:
	std::string m_TokenType;
	int m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;

public:
	IntegerToken()
	{
		m_TokenValue = 0;
	}
	IntegerToken(const std::string& tokenType)
	{
		m_TokenType = tokenType;
	}
	IntegerToken(const std::string& tokenType, int Value)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
	}
	IntegerToken(const std::string& tokenType, Position startPos)
	{
		m_TokenType = tokenType;
		m_StartPosition = startPos;
	}
	IntegerToken(const std::string& tokenType, int Value, Position startPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = startPos.Copy();
	}
	IntegerToken(const std::string& tokenType, int value, Position startPos, Position endPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = endPos.Copy();
	}

	~IntegerToken() {}

	std::string GetTokenType()
	{
		return m_TokenType;
	}

	int GetTokenValue()
	{
		if (m_TokenValue)
			return m_TokenValue;
		return NULL;
	}

	Position GetStartPosition()
	{
		return m_StartPosition;
	}

	Position GetEndPosition()
	{
		return m_EndPosition;
	}

	void SetTokenType(std::string tokType)
	{
		m_TokenType = tokType;
	}

	void SetTokenValue(int tokValue)
	{
		m_TokenValue = tokValue;
	}

	void SetStartPosition(Position newPos)
	{
		m_StartPosition = newPos;
	}

	void SetEndPosition(Position newPos)
	{
		m_EndPosition = newPos;
	}
	IntegerToken Copy()
	{
		return IntegerToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
	}

	/*explicit operator FloatToken() const
	{
		return FloatToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
	}*/
};

#endif