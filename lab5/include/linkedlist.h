#include <stdlib.h>
#include <iostream>

using namespace std;
template<class T> class LinkedList{
	private:
		class node{
			public:
			T data;
			node *next;
		};
		node *head;
		public:
		LinkedList();
		~LinkedList();
		void insert_first(T item);
		void insert_last(T item);
		int search(T item);
		void print_list();
		void delete_first();
		void delete_last();
		int delete_item(T item);
};