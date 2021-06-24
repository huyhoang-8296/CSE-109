#include "tree.h"
#include <iostream>
using namespace std;

// Inorder: L-N-R
// =>12-30-35-38-55-58-60-61-65-67-70-72-75-80-81
// Preorder: N-L-R
// Postorder: L-R-N

template<class T> class BST : public Tree<T>{
	private:
		class node{
		public:
			T data;
			node *left;
			node *right;
		};
		node *root;
		int size;
		void preorder(node *current){

		}
		void inorder(node *current){
			if(current == nullptr) { // base case
				return;
			}
			else{
				inorder(current->left); //L
				cout << current->data << endl; // N
				inorder(current->right);//R
			}
		}
		void postorder(node *current){

		}
 	public:
		BST(){
			root = NULL;
		}
		~BST(){

		}
		void inorder(){
			inorder(root);
		} // L-N-R;
		void preorder(){

		}
		void postorder(){

		}
		int search(T item){
			int count = 0;
			node *current;
			current = root;
			while(current != nullptr){
				if(current->data == item){
					count++;
					return count;
				}
				else if(current->data > item){					
					current = current->left;
				}
				else{
					current = current->right;
				}
				count++;
			}
			return count;
		}
		bool insert(T item){
			node *new_node = new node;
			new_node->data = item;
			new_node->left = nullptr;
			new_node->right = nullptr;

			if(root == nullptr){
				root = new_node;		
				return true;		
			}
			else{			
				node *current, *parent;
				current = root;
				while(current != nullptr){
					parent = current;
					if(current->data == item){
						return false;
					} // == should be overloaded.
					else if(current->data > item){// > should be overloaded.{
						current = current->left;
					}
					else{
						current = current->right;
					}
				}
				if(parent->data > item){
					parent->left = new_node;
				}
				else{
					parent->right = new_node;
				}
				return true;
			}		
		}
		
		bool remove(T item){
	
		}
		int getSize(){
			return 1;
		}		
};
