#include"fractions.h"
#include<iostream>
using namespace std;

fraction::fraction() :num(0), denominator(0){};

fraction::fraction(int n, int d) {
	num = n;
	denominator = d;
}

void fraction::setNum(int n) {
	num = n;
}
void fraction::setDen(int d) {
	denominator = d;
}
int fraction::getNum() {
	return num;
}
int fraction::getDen()
{
	return denominator;
}

int GCD(int n, int d) {
	{
		int a, b, r;
		if (n > d) {
			a = n;
			b = d;
		}
		else {
			a = n;
			b = d;
		}
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}

bool validOperand(char op)
{
	if (op != '+' && op != '-' && op != '*' && op != '/' && op != '<' && op != '>' && op != '!'&& op!='=') {
		cin.ignore(1, '/n');
		return false;
	}
	return true;
}


istream& operator>>(istream& in, fraction& obj) {
	char slash;
	in >> obj.num >> slash >> obj.denominator;
	//inout validation
	while (slash != '/') {
		cout << "Please enter a  valid fraction in the form a/b\n";
		in >> obj.num >> slash >> obj.denominator;
	}
	
	
	cout << endl;


	return in;

}
ostream& operator<<(ostream& out, fraction obj)
{
	int n, d;
	n = obj.getNum();
	d = obj.getDen();
	//exceptional cases 
	if (d == 1) {
		out << "The result is " << " " << n;
	}
	else if (n == 0) {
		out << "The result is 1\n";
	}
	else if (d == 0) {
		out << "Fraction cannot be processed!!\n";
	}
	else if (n < 0 || d < 0) {
		n = abs(n);
		d = abs(d);
		out << "The result is" << " " << '-' << n << '/' << d << "\n";
	}
	else
		out << "The result is" << " " << n << '/' << d << "\n";
	out << "\n";

	return out;
}

fraction fraction:: operator +(fraction obj) {

	
	int n, d;//sending into the new fraction
	int gcd;
	
	
	n = num * obj.denominator + obj.num * denominator;
	d = denominator * obj.denominator;
	gcd = GCD(n, d);
	//if gcd is 1 fraction cannot be furhter reduced
	if (gcd != 1) {
		n = n / gcd;
		d = d / gcd;
	}
	
	return fraction{ n,d };
}

fraction fraction:: operator -(fraction obj) {

	fraction temp;
	int n, d;//sending into the new fraction
	int gcd;
	n = num * obj.denominator - obj.num * denominator;
	d = denominator * obj.denominator;
	gcd = GCD(n, d);
	if (gcd != 1) {
		
		n = n / gcd;
		d = d / gcd;
	}
	return fraction{ n,d };
}
fraction fraction:: operator *(fraction obj) {

	fraction temp;
	int n, d;//sending into the new fraction
	int gcd;
	n = num * obj.num;
	d = denominator * obj.denominator;

	gcd = GCD(n, d);
	if (gcd != 1) {
		n = n / gcd;
		d = d / gcd;
	}
	temp.num = n;
	temp.denominator = d;
	return temp;
}
fraction fraction:: operator / (fraction obj) {

	fraction temp;
	int n, d;//sending into the new fraction
	int gcd;
	n = num * obj.denominator;
	d = denominator * obj.num;
	gcd = GCD(n, d);
	if (gcd != 1) {
		n /= n / gcd;
		d /= d / gcd;
	}
	return fraction{ n,d };
}
bool fraction::operator <(fraction obj) {
	int gcd1, gcd2;
	gcd1 = GCD(this->num, this->denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
	  num /= gcd1;
	denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num /= gcd2;
		obj.denominator /= gcd2;
	}
	return { num * obj.denominator < obj.num * denominator };

}
bool fraction::operator> (fraction obj) {
	int gcd1, gcd2;
	gcd1 = GCD(this->num, this->denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
		num /= gcd1;
		denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num /= gcd2;
		obj.denominator /= gcd2;
	}
	return { num * obj.denominator > obj.num* denominator };

}
bool fraction::operator==(fraction obj) {
	int gcd1, gcd2;

	gcd1 = GCD(this->num, this->denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
		num /= gcd1;
		denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num /= gcd2;
		obj.denominator /= gcd2;
	}
	 
	
	return{ (num == obj.num) && (denominator == obj.denominator) };
}

bool fraction::operator <=(fraction obj) {
	int gcd1, gcd2;
	gcd1 = GCD(this->num, this->denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
		num /= gcd1;
		denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num /= gcd2;
		obj.denominator /= gcd2;
	}
	
	return { (num * obj.denominator < obj.num * denominator) || (num==obj.num && denominator==obj.denominator) };
}

bool fraction::operator >=(fraction obj) {
	int gcd1, gcd2;
	gcd1 = GCD(num, denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
		num /= gcd1;
		denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num /= gcd2;
		obj.denominator /= gcd2;
	}
	return { (num * obj.denominator > obj.num* denominator) || (num == obj.num && denominator == obj.denominator) };
}



bool fraction::operator !=(fraction obj) {
	int gcd1, gcd2;
	gcd1 = GCD(this->num, this->denominator);
	gcd2 = GCD(obj.num, obj.denominator);

	if (gcd1 != 1) {
		num /= gcd1;
		denominator /= gcd1;
	}
	if (gcd2 != 1) {
		obj.num/= gcd2;
		obj.denominator/=gcd2;
	}


	return{ num==obj.num && denominator==obj.denominator  };
	
}





