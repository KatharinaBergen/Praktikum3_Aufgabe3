/*
Author: Kat Bergen
v.04 07.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#include "Token_stream.h"



Token Token_stream::get() {

	if (full) { full = false; return buffer; }

	char ch{ };
	std::cin >> ch;

	switch (ch) {

	case '?': return Token('?'); // Ausgabe von Gebrauchsanweisung
	case ';': return Token(';'); // Ende eines Rechenausdrucks
	case 'q': return Token('q'); // Programmende

	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token{ ch }; // jedes Zeichen ist sein eigenes Token

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // Zahl als Token
	{
		std::cin.putback(ch); // std::cin wir gebuffert/speichert ch

		double val{ };
		std::cin >> val; //ch wird jetzt als double gespeichert
		return Token{ val }; //und dem Tokenkonstruktor übergeben
	}

	default: error("Token invalid");

	}

}

void Token_stream::putback(const Token& t) {
	if (full) error("Token buffer is already full");
	else
	{
		buffer = t;
		full = true;
	}
}


//Standardkonstruktor
Token_stream::Token_stream() : full{ false }, buffer{}
{}



//Functions

double calculate(Token_stream& ts) // "plus" und "minus" behandeln
{
	double d1{ handleMultiplicationDivision(ts) };
	Token t1{};
	while (true)
	{
		t1 = ts.get();

		switch (t1.getKind())
		{
		case '+':
			std::cout << '+'; //print 
			d1 += handleMultiplicationDivision(ts);
			break;
		case '-':
			std::cout << '-'; //print 
			d1 -= handleMultiplicationDivision(ts);
			break;
		default: ts.putback(t1);
			return d1;
		}
	}
}


double handleMultiplicationDivision(Token_stream& ts) // "mal" und "geteilt durch" behandeln
{
	double d2{ handleBrackets(ts) };
	Token t2{};
	while (true)
	{
		t2 = ts.get();
		switch (t2.getKind())
		{
		case '*':
			std::cout << '*'; //print 
			d2 *= handleBrackets(ts);
			break;
		case '/': {
			std::cout << '/'; //print 
			double divisor{ handleBrackets(ts) };
			if (divisor == 0) error("Zero division error");
			d2 /= divisor;
			break;
		}
		default: ts.putback(t2);
			return d2;
		}
	}
}



double handleBrackets(Token_stream& ts) // Zahlen und Klammern behandeln
{
	Token t3{ ts.get() };

	if (t3.getKind() == '9') std::cout << t3.getValue();

	switch (t3.getKind())
	{
	case '-': return { handleNegativeNumbers(ts, t3) }; //added for NEGATIVE NUMBERS
	case '9': return (t3.getValue());
	case '(': {
		std::cout << '('; //print 
		double d3{ calculate(ts) };
		if (ts.get().getKind() != ')') error("keine rechte Klammer");
		else std::cout << ')'; //print 
		return d3;
	}

	default: error("kein Primary");
	}
}

double handleNegativeNumbers(Token_stream& ts, const Token& tk) // negative Zahlen behandeln
{
	char buffer0{ tk.getKind() };
	char buffer1{ ts.getBuffer().getKind() };
	Token t4{ ts.get() };
	switch (buffer1)
	{
	case '-':
		std::cout << '-' << t4.getValue(); //print 
		return { -t4.getValue() };
	default:
		switch (buffer0)
		{
		case '-':
			return { -t4.getValue() };
		default:
			return { t4.getValue() };
		}
	}

}

Token Token_stream::getBuffer() const { return buffer; }