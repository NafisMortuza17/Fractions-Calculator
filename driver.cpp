#include<iostream>
#include"fractions.h"

using namespace std;
int main()
{
	
	
	fraction x, y;
	char operand1, operand2;
	bool exit = false;
	char decision;
	do {
		cout << "\n";
		cout << "Enter two operands in the form a/b OPERAND c/d\n";
		cin >> x >> operand1;
		while (!validOperand(operand1)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid operand, please enter a valid operand from the list above and then enter second fraction\n";
			cin >> operand1;
		}
	    //if the input buffer has the operand '==' it would indicate the user wants to invoke a string operand
	 if (cin.peek()=='=') {
			
			cin >> operand2;//second operand
			cin >> y;//read in second fraction


			switch (operand1) {
			case'<':
				if (x <= y) {
					cout << "True\n";

				}
				else
					cout << "False\n";
				break;
			case'>':
				if (x >= y) {
					cout << "True\n";

				}
				else
					cout << "False\n";
				break;
			case'=':
				if (x == y) {
					cout << "True\n";

				}
				else
					cout << "False\n";
				break;
			case'!':
				if (!(x != y)) {
					cout << "True\n";

				}
				else
					cout << "False\n";
				break;

			}//end of switch statement

		}
		else {
			cin >> y;

			switch (operand1)
			{
			case'+':
				cout << "Adding...\n";
				cout << x + y << endl;
				break;
			case'-':
				cout << "Subtracting...\n";
				cout << x - y << endl;
				break;
			case'*':
				cout << "Multipying...\n";
				cout << x * y << endl;
				break;
			case'/':
				cout << "Dividing...\n";
				cout << x / y << endl;
				break;
			case'<':
				cout << "Comparing...\n";
				if (x < y) {
					cout << "True\n";
				}
				else
					cout << "False\n";
				break;
			case'>':
				cout << "Comparing...\n";
				if (x < y) {
					cout << "True\n";
				}
				else
					cout << "False\n";
				break;
			}
		}
		cout << endl;
		cout << "Do you wish to continue?\n";
		cin >> decision;
		while (decision != 'N' && decision != 'n' && decision != 'Y' && decision != 'y') {
			cout << "Please enter either a Y/N\n";
			cin.ignore(100, '\n');
			cin.clear();
			cin >> decision;
		}
		if (decision == 'n' || decision == 'N') {
			exit = true;
		}
	} while (!exit);

}
		
		
	