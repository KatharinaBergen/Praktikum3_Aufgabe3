#pragma once

class Token {

private:
	//variables
	double value;
	char kind;


public:
	//getters
	double getValue();
	char getKind();

	//setters
	void setValue(const double&);
	void setKind(const char&);

	//constructors
	Token(const double&, const char&);
	Token(const char&);
	Token();


};
