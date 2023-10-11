#pragma once
#include <iostream>
#include <iostream>

using namespace std;

class Employee {
protected:
	string namn;
	double r8;
public:
	Employee() { namn = ""; r8 = 0.0; };
	Employee(string nvn, double tw) { namn = nvn; r8 = tw; };
	double salary(int timmar, double r8 ) { return timmar * r8; };
	double healthcare(double r8, int timmar) { return(timmar * r8) * .05; };
	double vacationdays(int timmar) { return timmar * .07; };

};