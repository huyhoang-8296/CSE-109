// Huy Hoang
// CSE109 
// Assignment 4

#include "complex.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>


ostream& operator<<(ostream &write, Complex s);
istream& operator>>(istream &read, Complex &s);

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Need input file and output file." << endl;
		exit(0);
	}
	ifstream input_file;
	ofstream output_file;
	Complex a, c;
	// Read in input
	if(strcmp(argv[1],"input_file") != 0 && strcmp(argv[2],"output_file")){
		cout << "Need correct input file and output file." << endl;
		exit(0);
	}
	input_file.open("input_file.txt");
	string line;
	char op[] = {'+', '-','\0'};
	int line_no = 0;
	int i = 0;
	int plus = 0;
	int minus = 0;
	// put file into line
	while(input_file >> line){ 		
		i = line.find("i");
		plus = line.find("+");
		minus = line.find("-");		
	
	cout << a << endl;
	}
	
	input_file.close();
	return 0;
}

ostream& operator<<(ostream &write, Complex s){
	if(s.getImg() > 1){
		write << s.getReal() << "+" << s.getImg() << "i";
	}
	else if(s.getImg() < -1){
		write << s.getReal() << "-" << s.getImg() * (-1) << "i";
	}
	else if(s.getImg() == 1){
		write << s.getReal() << " + i" ;
	}
	else if(s.getImg() == -1){
		write << s.getReal() << " - i" ;
	}
	else{
		write << s.getReal();
	}
 	return write;
}

istream& operator>>(istream &read, Complex &s){
	string input;
	char ch; 
	int i;
 	read >> input;
	i = input.find("i"); 	 	
 	return read;
}
