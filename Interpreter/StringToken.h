#ifndef _STRINGTOKEN_CPP
#define _STRINGTOKEN_CPP


class StringToken
{
private:
	std::string m_TokenType;
	std::string m_TokenValue;
	Position m_StartPosition;
	Position m_EndPosition;
public:
	StringToken()
	{

	}
	StringToken(std::string tokenType)
	{
		m_TokenType = tokenType;
	}
	StringToken(std::string tokenType, std::string Value)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
	}
	StringToken(std::string tokenType, Position startPos)
	{
		m_TokenType = tokenType;
		m_StartPosition = startPos;
	}
	StringToken(std::string tokenType, std::string Value, Position startPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = Value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = startPos.Copy();
	}
	StringToken(std::string tokenType, std::string value, Position startPos, Position endPos)
	{
		m_TokenType = tokenType;
		m_TokenValue = value;
		m_StartPosition = startPos.Copy();
		m_EndPosition = endPos.Copy();
	}

	~StringToken() {}

	std::string GetTokenType()
	{
		return m_TokenType;
	}

	std::string GetTokenValue()
	{
		return m_TokenValue;
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

	void SetTokenValue(std::string tokValue)
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
	StringToken Copy()
	{
		return StringToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
	}
};
#endif