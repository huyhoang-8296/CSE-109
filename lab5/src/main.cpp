// Huy Hoang
// CSE 109
// Lab 5

#include "linkedlist.cpp"
#include "hashtable.h"
#include "BST.cpp"
#include <fstream>

int main(){
	// Variables declaration
	ifstream inputFile;	
	HashTable studentHashTable(500);	
	HashTable studentHashTable2(250);
	LinkedList<Student> studentList;
	BST<Student> studentBST;
	Student student; 
	Student s[10];
	
	// Read in the students.txt file
	inputFile.open("students.txt");
	if (inputFile.fail()){
		cout << "Cannot open students.txt for reading.";
		exit(1);
	}
	else{
		printf("students.txt opened successfully.\n");
	}
	// Create an array of studentID and then put them into a Student s array
	int studentid[10] ={91242, 87351, 13385, 55555, 37867, 98296, 22222, 62985, 33333, 48851};
	
	for(int j = 0; j < 10; j++){
		s[j].setID(studentid[j]);
	}
	
	// Number of searches for each data structures
	int countBST = 0;
	int countHash = 0;
	int countLL = 0;
	int countHash2 = 0;

	// Read in the students.txt file for each structure
	while (!inputFile.eof()){
		inputFile >> student;
		studentList.insert_first(student);
		studentHashTable.hashInsert(student);
		studentHashTable2.hashInsert(student);
		studentBST.insert(student);		
	}	

	cout << "ID" << "\t\tHASH" << "\tLL" << "\t\tBST" << "\t\tHASH2" << endl;
	
	// Incrementing the search count for each structures and print out results
	for(int i = 0; i < 10; i++){
		countLL = studentList.search(s[i]);
		countBST = studentBST.search(s[i]);
		countHash = studentHashTable.hashSearch(s[i]);
		countHash2 = studentHashTable2.hashSearch(s[i]);
		cout << s[i].getID() << "\t" << countHash << "\t\t" << countLL << "\t\t" << countBST << "\t\t" << countHash2 << endl;
	}
	inputFile.close();
	return 0;
}