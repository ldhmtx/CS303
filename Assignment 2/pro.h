#pragma once
#include "employee.h"
#include <iomanip>

//class for building a professional employee

class Professional : public Employee {
private: //all specific variables for this class
	double monthsal;
	double vacdag;
	double hc;
public: //functions to build emplpyee
	Professional(string n = "unknown", double r = 0.0, int t = 0) { //default constructor
		namn = n;
		monthsal = salary(t,r);
		vacdag = vacationdays(t);
		hc = healthcare(t, r);
	}
	double salary(int timmar, double r8) { return (timmar * r8)*4; }; //finding salary assuming taking weekly hours to calculate
	double healthcare(double r8, int timmar) { return((timmar * r8) * .05)*4; }; //calculating healthcase assuming 5% contribution
	double vacationdays(int timmar) { return (timmar * .07); }; // calculating vacation days assuming 7% accure rate
	void print() { //printing out all information about this type of employee
		cout << "Professional Employee Stats:\n\nName: " << namn << 
			"\nMonthly salary: $" << fixed << setprecision(2) << monthsal <<
			"\nNumber of vacation days for the month:" << setprecision(2)<<vacdag << 
			"\nMonthly healthcare contributions: $" << fixed << setprecision(2) << hc <<
			endl;
	}
};
