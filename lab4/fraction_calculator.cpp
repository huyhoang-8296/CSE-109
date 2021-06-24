#include "fraction.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


ostream& operator<<(ostream &write, Fraction s);
istream& operator>>(istream &read, Fraction &s);

int main(){
	int a, b, c, d;
	char slash, op[2];
	Fraction x, y;
	Fraction result;
	bool hello;
	char option;
	do{
		cout << "Enter the numerator and denominator: ";
		cin >> a >> slash >> b >> op >> c >> slash >> d;
		cout << a << "/" << b << + " " << op << + " " << c << "/" << d << endl;

		x.setNumerator(a); x.setDenominator(b);
		y.setNumerator(c); y.setDenominator(d);		
			if(op[0] == '+'){
				result = x + y;
				cout << "= " << result.toString() << endl;
			}
			else if(op[0] == '-'){
				hello = x < y;
				if(hello == true){
					result = y - x;
					cout << "= -" << result.toString() << endl;
				}
				else{
					result = x - y;
					cout << "= " << result.toString() << endl;
				}	
			}
			else if(op[0] == '*'){
				result = x * y;
				cout << "= " << result.toString() << endl;
			}
			else if(op[0] == '/'){
				result = x / y;
				cout << "= " << result.toString() << endl;
			}
			else if(op[0] == '<'){
				hello = x < y;
				if(hello == 1){
					cout << "= " << "true" << endl;
				}
				else{
					cout << "= " << "false" << endl;
				}
			}
			else if(op[0] == '>'){
				hello = x > y;
				if(hello == 1){
					cout << "= " << "true" << endl;
				}
				else{
					cout << "= " << "false" << endl;
				}
			}
			else if(strcmp(op,"==") == 0){
				hello = x == y;
				if(hello == 1){
					cout << "= " << "true" << endl;
				}
				else{
					cout << "= " << "false" << endl;
				}
			}
			else if(strcmp(op,"<=") == 0){
				hello = x <= y;
				if(hello == 1){
					cout << "= " << "true" << endl;
				}
				else{
					cout << "= " << "false" << endl;
				}
			}
			else if(strcmp(op,">=") == 0){
				hello = x >= y;
				if(hello == 1){
					cout << "= " << "true" << endl;
				}
				else{
					cout << "= " << "false" << endl;
				}
			}

		cout << "Do you want to perform another operation? (y/n): " ;
		cin >> option; 
	}while(option == 'y');
	return 0;
}


ostream& operator<<(ostream &write, Fraction s){
	char op;
	Fraction b;
 	write << s.getNumerator() << "/"<< s.getDenominator() << op << b.getNumerator() << "/" << b.getDenominator();
 	return write;
}
istream& operator>>(istream &read, Fraction &s){
 	int numerator; int denominator;
	int numerator2; int denominator2;
	Fraction b;
	char op; 
 	read >> numerator >> op >> denominator >> numerator2 >> op >> denominator2;
 	s.setNumerator(numerator); s.setDenominator(denominator); 
	b.setNumerator(numerator2); b.setDenominator(denominator2);
 	return read;
}
