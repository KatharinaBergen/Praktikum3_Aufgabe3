/*
Author: Kat Bergen
v.04 07.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#pragma once
#include "Token.h"
#include "MyError.h"
#include <iostream>

class Token_stream {

private:
	bool full;
	Token buffer;

public:
	Token get();
	void putback(const Token&);
	Token getBuffer() const;

	Token_stream(); //Standardkonstruktor

};

//Functions:

double calculate(Token_stream&);
double handleMultiplicationDivision(Token_stream&);
double handleBrackets(Token_stream&);
double handleNegativeNumbers(Token_stream&, const Token&);