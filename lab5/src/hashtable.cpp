#include "hashtable.h"

HashTable::HashTable(){
 	capacity = 50;
 	HT = new Node*[capacity];
}
HashTable::HashTable(int cap){
 	capacity = cap;
 	HT = new Node*[capacity];
}
HashTable::~HashTable(){
}
int HashTable::computeHash(Student s){	
 	return s.getID() % capacity;
}
int HashTable::hashSearch(Student s){
	int count = 0;
	Node *head = HT[computeHash(s)];
	if (head == nullptr){
		count++;
		return count;
 	}
	else{
		while(head != NULL){ // collision case
			if(head->student == s){
				count++;
				return count;
			}
			count++;
			head = head->next;					
		}
	return count;
	}
}
void HashTable::hashInsert(Student s){
	Node *head = HT[computeHash(s)];
	Node *new_node = new Node;
	new_node->student = s;
	new_node->next = nullptr;
	if (head == NULL) // first element in the LL
		HT[computeHash(s)] = new_node;
	else{
		new_node->next = head;
		HT[computeHash(s)] = new_node;
	}
}