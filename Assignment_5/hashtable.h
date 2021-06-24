#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cctype>
#include <cwctype>
#include <algorithm>
using namespace std;

class HashTable{
 	private:
		class Node{
	public:
		string text;
		Node *next;
 	};
	Node **HT; //dynamic array for the hash table
	int capacity;
	int computeHash(string item);
	public:
	HashTable();
	HashTable(int cap);
	~HashTable();
	bool hashSearch(string item);
	void hashInsert(string item);
};