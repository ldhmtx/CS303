#pragma once
#include "employee.h"
#include "iomanip"

//class for building non professional employees

class NonPro : public Employee {
private: //all specific values for this type of employee
	double helgsal; 
	double vacdag;
	double hc;
public://functions for calculating values we need
	NonPro(string n = "unknown", double r = 0.0, int t =0) { //default constructor
		namn = n;
		helgsal = salary(t, r);
		vacdag = vacationdays(t);
		hc = healthcare(t, r);
	}
	double salary(int timmar, double r8) { return timmar * r8; }; //finding salary
	double healthcare(double r8, int timmar) { return((timmar * r8) * .05); }; //calculating healthcare contributions assuming ~5%
	double vacationdays(int timmar) { return (timmar * .07)/4; }; //calculating vacation days assuming taking from hours worked
	void print() { //printing out all information of this employee
		cout << "NonProfessional Employee Stats:\n\nName: " << namn <<
			"\nWeekly salary: $" << fixed << setprecision(2) << helgsal <<
			"\nNumber of vacation days for the month:" << fixed<<setprecision(2) << vacdag <<
			"\nMonthly healthcare contributions: $" << fixed << setprecision(2) << hc <<
			endl;
	}
};