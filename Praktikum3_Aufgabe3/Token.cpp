/*
Author: Kat Bergen
v.01 01.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#include "Token.h"



//getter
double Token::getValue() const { return value; }
char Token::getKind() const { return kind; }

//setter
void Token::setValue(const double& n) { value = n; }
void Token::setKind(const char& c) { kind = c; }

//constructors
Token::Token(const double& n) : value{ n }, kind{ '9' }
{}
Token::Token(const char& c) : value{ 0.0 }, kind{ c }
{}
Token::Token() : value{ 0.0 }, kind{ '9' }
{}

void Token::print() const {
	if (kind == '9') std::cout << value;
	else std::cout << kind;
}
