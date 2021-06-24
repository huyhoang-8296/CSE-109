// Class implementation
#include "fraction.h"

using namespace std;

// Default contrustor
Fraction::Fraction(){
	numerator = 0; denominator = 1;
}

Fraction::Fraction(int numerator, int denominator){
	this->numerator = numerator; this->denominator = denominator;
}
//getters

int Fraction::getNumerator(){return numerator;}
int Fraction::getDenominator(){return denominator;}

string Fraction::toString(){
 	string out;
	 	if(numerator == denominator){
		 	out = to_string(numerator/denominator) ;
	 	}
	 	else if(numerator % denominator == 0){
 			out = to_string(numerator/denominator) ;
	 	}
		else{
			out = to_string(numerator)+ "/" + to_string(denominator);
		}
 	return out;
}

//setters
void Fraction::setNumerator(int x){this->numerator = x;}
void Fraction::setDenominator(int y){this->denominator = y;}

int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	if(b == 0){
		return a;
	}
	if(a == b){
		return a;
	}
	if(a > b){
		return gcd(a-b,b);
	}
	else{
		return gcd(a, b-a);
	}
}

void Fraction::reduce(){
	int common = 0;
	common = gcd(numerator,denominator);
	numerator = numerator / common;
	denominator = denominator / common;
}

Fraction Fraction::operator+(Fraction f){
  Fraction c;
  c.numerator = numerator * f.denominator + denominator * f.numerator; 
  c.denominator = denominator * f.denominator; 
	// numerator and denominator are this object numerator and denominator
	c.reduce();
  return c;
}

Fraction Fraction::operator-(Fraction f){
	Fraction c;
	c.numerator = numerator * f.denominator + denominator * f.numerator * (-1);
	c.denominator = denominator * f.denominator; 
	c.reduce();		
	return c;
}

Fraction Fraction::operator*(Fraction f){
	Fraction c;
	c.numerator = numerator * f.numerator; 
	c.denominator = denominator * f.denominator; 
	c.reduce();
	return c;
}

Fraction Fraction::operator/(Fraction f){
	Fraction c;
	c.numerator = numerator * f.denominator; 
	c.denominator = denominator * f.numerator;
	c.reduce();
	return c;
}

bool Fraction::operator==(Fraction f){
	this->reduce();
	f.reduce();
	if(numerator == f.numerator && denominator == f.denominator){
		return true;
	}
	return false;
}

bool Fraction::operator!=(Fraction f){
	this->reduce();
	f.reduce();
	if(numerator != f.numerator && denominator != f.denominator){
		return true;
	}
	return false;
}

bool Fraction::operator<(Fraction f){
	if(denominator != f.denominator){
		numerator = numerator * f.denominator;
		f.numerator = f.numerator * denominator;
		denominator = denominator * f.denominator;
		if(numerator < f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
	else if(denominator == f.denominator){
		if(numerator < f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Fraction::operator<=(Fraction f){
	if(denominator != f.denominator){
		numerator = numerator * f.denominator;
		f.numerator = f.numerator * denominator;
		denominator = denominator * f.denominator;
		if(numerator <= f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
	else if(denominator == f.denominator){
		if(numerator <= f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Fraction::operator>(Fraction f){
	if(denominator != f.denominator){
		numerator = numerator * f.denominator;
		f.numerator = f.numerator * denominator;
		denominator = denominator * f.denominator;
		if(numerator > f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
	else if(denominator == f.denominator){
		if(numerator > f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
}

bool Fraction::operator>=(Fraction f){
	if(denominator != f.denominator){
		numerator = numerator * f.denominator;
		f.numerator = f.numerator * denominator;
		denominator = denominator * f.denominator;
		if(numerator >= f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
	else if(denominator == f.denominator){
		if(numerator >= f.numerator){
			return true;
		}
		else{
			return false;
		}
	}
}

