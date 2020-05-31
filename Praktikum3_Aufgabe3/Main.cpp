/*
Author: Kat Bergen
v.02 31.05.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#include <iostream>
using std::cout;
using std::cin;

#include "MyError.h"

int main() try
{
	int x{};
	int y{};
	char op{};

	//user input
	cout << "Rechenausdruck (mit +,-,*,/, Ende mit ;) "; // wie z.B. 2*3+4;
	cin >> x;
	if (!cin) error("Kein linker Operand");


	while (cin >> op && op != ';') {
		if (!cin) error("Kein Operator");

		cin >> y;
		if (!cin) error("Kein rechter Operand");

		switch (op) {
		case '+': x += y; break;
		case '-': x -= y; break;
		case '*': x *= y; break;
		case '/':
		{
			if (y == 0) error("Teilung durch 0 nicht möglich.");
			x /= y; break;
		}
		default: error("Unbekannter Operator");
		}//switch()
	}// while()
	cout << "Ergebnis: " << x << std::endl;
	return 0;
}

catch (std::runtime_error& e)
{
	std::cerr << e.what();
}

catch (...)
{
	std::cerr << "unknown error";
}