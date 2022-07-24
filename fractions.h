#pragma once
#include<iostream>
using namespace std;
class fraction {
	int num, denominator;
public:
	fraction();//default contuctor
	fraction(int, int);//paramterized constructor


	void setNum(int n);

	void setDen(int d);

	int getNum();

	int getDen();

 //prototypes of all member operators
	fraction operator +(fraction);

	fraction operator -(fraction);

	fraction operator *(fraction);

	fraction operator / (fraction);

	bool operator == (fraction);

	bool operator!= (fraction);

	bool operator<(fraction);

	bool operator>(fraction);
    
	bool operator<=(fraction);

    bool operator>=(fraction);

	friend istream& operator>>(istream& in, fraction&);//read into the members directly



};

ostream& operator<<(ostream& out, fraction);

int GCD(int, int);//gcd function

bool validOperand(char);//input validation