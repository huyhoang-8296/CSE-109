#include "student.h"

class HashTable{
 private:
		class Node{
	public:
		Student student;
		Node *next;
 };
	Node **HT; //dynamic array for the hash table
	int capacity;
	int computeHash(Student item);
	public:
	HashTable();
	HashTable(int cap);
	~HashTable();
	int hashSearch(Student item);
	void hashInsert(Student item);
};