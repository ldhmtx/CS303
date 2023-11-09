#pragma once 
#include <string>
#include <iostream>
#include <stack>


using namespace std;

void cenmenu(bool &dog);

//first part of assignment:
void bearbeta(char i,  stack<char>& utvard,string &pf);
void i2f();
bool isOP(char i);
int precedence(char i);
bool goodBalance(const string& giv);

//second part of assignment:
void qLaga();

