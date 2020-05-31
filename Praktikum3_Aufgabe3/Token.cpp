#include "Token.h"


//getter
double Token::getValue() { return value; }
char Token::getKind() { return kind; }

//setter
void Token::setValue(const double& n) { value = n; }
void Token::setKind(const char& c) { kind = c; }

//constructors
Token::Token(const double& n, const char& c) : value{ n }, kind{ c }
{}
Token::Token(const char& c) : value{ 0 }, kind{ c }
{}
Token::Token() : value{ 0 }, kind{ ' ' }
{}
