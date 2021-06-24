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
int HashTable::computeHash(User s){	
	int hash = 0;
	for(int i=0; i < s.getUsername().length(); i++)
		hash += s.getUsername()[i];
	return hash % capacity;
}

User HashTable::hashSearch(User s){
 	Node *head = HT[computeHash(s)];
 	if (head == nullptr){
 		exit(1);
 	}
 	else{
 		while(head != NULL){ // collision case
 			if(head->user.getUsername() == s.getUsername())
 				return head->user;
 			head = head->next;
 	}
	head->user.setUsername("") ;
 	return head->user;
 	}
}
void HashTable::hashInsert(User s){
	Node *head = HT[computeHash(s)];
	Node *new_node = new Node;
	new_node->user = s;
	new_node->next = nullptr;
	if (head == NULL) // first element in the LL
		HT[computeHash(s)] = new_node;
	else{
		new_node->next = head;
		HT[computeHash(s)] = new_node;
	}
}

void HashTable::resetPassword(User s){
	Node *head = HT[computeHash(s)];
 	if (head == nullptr){
 		cout << "There's no data to reset password." << endl;
 	}
 	else{
 		while(head != NULL){ // collision case
 			if(head->user == s)
 				s.newPassword();
 			head = head->next;
 		}	
 	}
	cout << "Error Message" << endl;
}

ostream& HashTable writeHash(ostream& write){
	return write;
}