#include "linkedlist.h"

template<class T> LinkedList<T>::LinkedList(){
 	head = NULL;
}
template<class T> LinkedList<T>::~LinkedList(){
	if(head != NULL){
		node *current = head;
		node *delete_node;
	while(current != NULL){
		head = current;
		current = current->next;
		delete head;
 	}
 }
}
template<class T> void LinkedList<T>::insert_first(T item){
	node *new_element = new node;
	new_element->data = item;
	new_element->next = head;
	head = new_element;
}
template<class T> void LinkedList<T>::insert_last(T item){
	node *new_element = new node;
	new_element->data = item;
	new_element->next = NULL;
	
	if(head == NULL)
		head = new_element;
	else{
		node *current = head;
	while(current->next != NULL)
		current = current->next;
	
	current->next = new_element;
	}
}

template<class T> int LinkedList<T>::search(T item){
	int count = 0;
 	if(head == NULL)
 		return 0;
 	else{
		node *current = head;
 	while(current != NULL){
 		if (current->data == item) {
			count++;
 			return count;
 		}
 		current = current->next;
		count++;
 	}
 	return count;
 }
}
template<class T> void LinkedList<T>::print_list(){
	node *current = head;
	while(current != NULL){
		cout << current->data << endl;
		current = current->next;
	}
}

template<class T> void LinkedList<T>::delete_last(){
 if (head != NULL){
	node *deleted;
	node *current = head;
 	while(current->next != NULL)
 		if(current->next->next == NULL){
 			break;
 		}
 		else
 			current = current->next;
 	deleted = current->next;
 	current->next = NULL;
 	delete deleted;
 	}
}