#include "user.h"
#include <string>
#include <iostream>
#include <string.h>

class HashTable{
  private:
		class Node{
		public:
			User user;
			Node *next;
 	};
	Node **HT; //dynamic array for the hash table
	int capacity;
	int computeHash(User item);
	public:
	HashTable();
	HashTable(int cap);
	~HashTable();
	void resetPassword(User u);
	User hashSearch(User s);
	void hashInsert(User s); 
	ostream& writeHash(ostream& write);
};
