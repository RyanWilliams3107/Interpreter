#ifndef _TOKEN_CPP
#define _TOKEN_CPP
#include "Position.h"
#include "Operator.h"

#define DIGITS "0123456789"

#define TOK_INTEGER "INTEGER"
#define TOK_FLOAT "FLOAT"
#define TOK_STRING "STRING"
#define TOK_IDENTIFIER "IDENTIFIER"
#define TOK_EQUALS "EQUALS"
#define TOK_PLUS "PLUS"
#define TOK_MINUS "MINUS"
#define TOK_MULTIPLY "MULTIPLY"
#define TOK_DIVIDE "DIVIDE"
#define TOK_LEFTPAREN "LEFTPAREN"
#define TOK_RIGHTPAREN "RIGHTPAREN"
#define TOK_POWER "POWER"
#define TOK_EOF "EOF"

#include "IntegerToken.h"
#include "FloatToken.h"
#include "OperatorToken.h"
#include "StringToken.h"

#endif


