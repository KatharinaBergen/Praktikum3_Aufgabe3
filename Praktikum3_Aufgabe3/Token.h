/*
Author: Kat Bergen
v.01 01.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#pragma once
#include <iostream>

class Token {

private:
	//variables 
	double value;
	char kind;


public:
	//getters
	double getValue() const;
	char getKind() const;

	//setters
	void setValue(const double&);
	void setKind(const char&);

	//constructors
	Token(const double&);
	Token(const char&);
	Token();

	void print() const;

};
