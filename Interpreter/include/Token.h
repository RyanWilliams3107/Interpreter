#ifndef _TOKEN_CPP
#define _TOKEN_CPP
#include <iostream>

#define TOK_INTEGER "INTEGER"
#define TOK_FLOAT "FLOAT"
#define TOK_STRING "STRING"
#define TOK_IDENTIFIER "IDENTIFIER"
#define TOK_EQUALS "EQUALS"
#define TOK_PLUS "PLUS"
#define TOK_MINUS "MINUS"
#define TOK_MULTIPLY "MULTIPLY"
#define TOK_DIVIDE "DIVIDE"
#define TOK_MOD "MOD"
#define TOK_POW "POW"
#define TOK_LEFTPAREN "LEFTPAREN"
#define TOK_RIGHTPAREN "RIGHTPAREN"
#define TOK_POWER "POWER"
#define TOK_EOF "EOF"

static const std::string DIGITS = "0123456789";
static const std::string DIGITSPLUSDOT = DIGITS + '.';
static const std::string ASCII_LOWER = "abcdefghijklmnopqrstuvwxyz";
static const std::string ASCII_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string ASCII_LETTERS = ASCII_LOWER + ASCII_UPPER;


#include "IntegerToken.h"
#include "FloatToken.h"
#include "OperatorToken.h"
#include "StringToken.h"

#endif


