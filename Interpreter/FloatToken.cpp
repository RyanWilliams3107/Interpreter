#include "FloatToken.h"


FloatToken::FloatToken()
{
    m_TokenValue = 0.0f;
}

FloatToken::FloatToken(const std::string& tokenType)
{
    m_TokenType = tokenType;
}

FloatToken::FloatToken(const std::string& tokenType, float Value)
{
    m_TokenType = tokenType;
    m_TokenValue = Value;
}

FloatToken::FloatToken(const std::string& tokenType, Position startPos)
{
    m_TokenType = tokenType;
    m_StartPosition = startPos.Copy();
    m_EndPosition = startPos.Copy();
}

FloatToken::FloatToken(const std::string& tokenType, float Value, Position startPos)
{
    m_TokenType = tokenType;
    m_TokenValue = Value;
    m_StartPosition = startPos.Copy();
    m_EndPosition = startPos.Copy();
}

FloatToken::FloatToken(const std::string& tokenType, float value, Position startPos, Position endPos)
{
    m_TokenType = tokenType;
    m_TokenValue = value;
    m_StartPosition = startPos.Copy();
    m_EndPosition = endPos.Copy();
}

FloatToken::~FloatToken()
{
}

std::string FloatToken::GetTokenType()
{
    return m_TokenType;
}

float FloatToken::GetTokenValue()
{
    return m_TokenValue;
}

Position FloatToken::GetStartPosition()
{
    return m_StartPosition;
}

Position FloatToken::GetEndPosition()
{
    return m_EndPosition;
}

void FloatToken::SetTokenType(const std::string& tokType)
{
    m_TokenType = tokType;
}

void FloatToken::SetTokenValue(float tokValue)
{
    m_TokenValue = tokValue;
}

void FloatToken::SetStartPosition(Position newPos)
{
    m_StartPosition = newPos;
}

void FloatToken::SetEndPosition(Position newPos)
{
    m_EndPosition = newPos;
}

FloatToken FloatToken::Copy()
{
    return FloatToken(m_TokenType, m_TokenValue, m_StartPosition, m_EndPosition);
}


