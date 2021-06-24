#include "complex.h"

Complex::Complex(){
	real = 0; img = 0;
}

Complex::Complex(double real, double img){
	this->real = real; this->img = img;
}

double Complex::getReal(){return real;}
double Complex::getImg(){return img;}

void Complex::setReal(double real){this->real = real;}
void Complex::setImg(double img){this->img = img;}

Complex Complex::operator+(Complex s){
	Complex result;
	result.real = real + s.real;
	result.img = img + s.img;
	return result;
}

Complex Complex::operator-(Complex s){
	Complex result;
	result.real = real - s.real;
	result.img = img - s.img;
	return result;
}

Complex Complex::operator*(Complex s){
	Complex result;
	result.real = real * s.real - img * s.img;
	result.img = real * s.img + img * s.real;
	return result;
}

bool Complex::operator==(Complex s){
	if(real == s.real && img == s.img){
		
		return true;
	}
	
	return false;
}

bool Complex::operator!=(Complex s){
	if(real != s.real || img != s.img){	
		return true;
	}
	
	return false;
}


