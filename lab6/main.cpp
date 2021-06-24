#include "student.h"
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>

int main(){
	Student student, s[10];
	ifstream inputFile;

	list<Student> studentList;	 // List
	map<int, Student> studentMap; // BST
	unordered_map<int, Student> studentHashTable; //Hash

	int studentid[10] ={91242, 87351, 13385, 55555, 37867, 98296, 22222, 62985, 33333, 48851};
	
	for(int j = 0; j < 10; j++){
		s[j].setID(studentid[j]);
	}

	inputFile.open("students.txt");
	if (inputFile.fail()){
		cout << "Cannot open students.txt for reading.";
		exit(1);
	}
	else{
		printf("students.txt opened successfully.\n");
	}
	while (!inputFile.eof()){
		inputFile >> student;
		studentList.push_back(student);
		studentMap[student.getID()] = student;
		studentHashTable[student.getID()] = student;
	}
	 
	map<int, Student>::iterator mapIterator;
	unordered_map<int, Student>::iterator hashIterator;
	list<Student>::iterator listIterator;

	int countBST = 0;
	int countHash = 0;
	int countLL = 0;

	clock_t startLL, endLL, startBST, endBST, startMap, endMap;
	cout << "ID" << "\t\tLL" << "\t\tBST" << "\t\tHASH" << endl;

	for(int i = 0; i < 10; i++){
		startLL = clock();		
		listIterator = find(studentList.begin(), studentList.end(), s[i]);
		endLL = clock();
		
		startBST = clock();
		studentHashTable.find(studentid[i]);
		endBST = clock();
		
		startMap = clock();
		studentMap.find(studentid[i]);		
		endMap = clock();
		
		double timeLL = double (endLL - startLL);
		double timeBST = double (endBST - startBST);
		double timeMap = double (endMap - startMap);
		
		cout << studentid[i] << "\t" << timeLL << "\t\t" << timeBST << "\t\t" << timeMap << endl;
	}
	inputFile.close();
	return 0;
}