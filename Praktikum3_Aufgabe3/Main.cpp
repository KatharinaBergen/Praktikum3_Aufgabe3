/*
Author: Kat Bergen
v.04 07.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#include <iostream>
using std::cout;
using std::cin;

#include "MyError.h"
#include "Token.h"
#include "Token_stream.h"

int main() try
{
	Token tok{};
	Token_stream ts{}; // Standardkonstruktor?!


	do
	{
		cout << "Bitte geben Sie die Kalkulation ein, die Sie berechnen möchten.\n> ";
		tok = ts.get();
		if (tok.getKind() == '?')
		{
			std::cout << "Sie können eine Rechneroperation mit +, -, *, / und Klammern durchführen.\nUm eine Ergebnis zu erhalten, Tippen Sie bitte ';' ein. Um das Programm zu beenden, Tippen Sie bitte 'q' ein.\n\n";
			continue;
		}
		if (tok.getKind() == ';') continue;
		if (tok.getKind() == 'q') break;
		ts.putback(tok);
		cout << " = " << calculate(ts) << std::endl << std::endl;

		if (ts.get().getKind() == '?') std::cout << "Sie können eine Rechneroperation mit +, -, *, / und Klammern durchführen.\nUm eine Ergebnis zu erhalten, Tippen Sie bitte ';' ein. Um das Programm zu beenden, Tippen Sie bitte 'q' ein.\n\n";

		ts = Token_stream(); //resets ts to empty, so as to avoid duplicate cout

	} while (cin);

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