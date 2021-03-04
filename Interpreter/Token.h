#ifndef _TOKEN_CPP
#define _TOKEN_CPP
#include "Position.h"
#include "Operator.h"


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

const std::string DIGITS = "0123456789";
const std::string DIGITSPLUSDOT = DIGITS + '.';
const std::string ASCII_LOWER = "abcdefghijklmnopqrstuvwxyz";
const std::string ASCII_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ASCII_LETTERS = ASCII_LOWER + ASCII_UPPER;


#include "IntegerToken.h"
#include "FloatToken.h"
#include "OperatorToken.h"
#include "StringToken.h"

#endif


