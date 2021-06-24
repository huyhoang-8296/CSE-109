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
int HashTable::computeHash(string s){
	int hash = 0;
	for(int i=0; i<s.length(); i++)
		hash += s[i];
	return hash % capacity;
}
bool HashTable::hashSearch(string s){
	Node *head = HT[computeHash(s)];
	if (head == nullptr){
		return false;
 	}
 	else{
		while(head != NULL){ // collision case
			if(head->text == s)
				return true;
				head = head->next;
			}
		return false;
	}
}
void HashTable::hashInsert(string s){
	Node *head = HT[computeHash(s)];
	Node *new_node = new Node;
	new_node->text = s;
	new_node->next = nullptr;
	if (head == NULL) // first element in the LL
		HT[computeHash(s)] = new_node;
	else{
		new_node->next = head;
		HT[computeHash(s)] = new_node;
	}
}

