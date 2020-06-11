/*
Author: Kat Bergen
v.01 01.06.2020
source folder: C:\Users\katha\source\repos\

calculator program

pad1-P3-A2
*/

#include "MyError.h"


void error(const std::string& s)
{
	throw std::runtime_error{ s };
}