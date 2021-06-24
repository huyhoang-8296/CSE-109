#include "hashtable.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>

int main(){
	ifstream input_file;
	char filename[20] = "users.txt";
	
	// Check for the file
	input_file.open(filename);
	if (input_file.fail()){
		cout << "Cannot open users.txt for reading.";
		exit(1);
	}
	cout << "File users.txt loaded successfully." << endl;
	// Create a hashtable data and a user object
	HashTable data(100);
	User s, p;
	int i;
	// Read in the users.txt into object s and put each one of them in the hashtable
	while (!input_file.eof()){
		input_file >> s;
		cout << s << endl;
		data.hashInsert(s);
		i++;
	}
	// Create a variable option for the user to choose;
	int option = 0;
	string username = " ";
	string password = " ";
	bool priv = 0;
	int count = 0;
	
	do{
		cout << "Enter login credentials (username and password): " << endl;
		cout << "username: ";
		cin >> username;
		cout << "password: ";
		cin >> password;
		p.setUsername(username);
		p = data.hashSearch(p);
		if(count == 2){
			cout << "Access denied after three trials." << endl;
			exit(1);
		}
		if(p.getUsername() != "" && p.getPassword() == password){
			if(p.getPriv() == 1){
				break;
			}
			else{
				cout<<"You do not have administrator access rights. You cannot access the file." << endl;
				exit(1);
			}				
		}
		else{
			cout << "Invalid credentials. Try again." << endl;
			count++;
		}
	}while(count < 3);
		
	do{
		cout << "Select an operation: \n1: Add a new user\n2: Reset Password of an existing user\n3: Logout\n";
		cin >> option;
		switch(option){
			case 1: 
				cout << "Enter a username: ";
				cin >> username;
				cout << "Enter user privileges (1 for admin, 0 for user): ";
				cin >> priv;
				p.setUsername(username);
				p.setPriv(priv);
				data.hashInsert(p);
				cout << p << endl;
				cout << "New user added successfully." << endl;
			break;
			case 2:
				cout << "Enter username: " << endl;
				cin >> username;
				p.setUsername(username);
				data.resetPassword(p);
				cout << p << endl;
				cout << "Password reset successfully." << endl;
			break;
			case 3:
				cout << "Updating data files ...\nLogout completed." << endl;
				exit(0);
			default:
				cout << "Wrong option" << endl;
				exit(1);
			}
	  }while(option < 4);	
	
	input_file.close();
	return 0;
}

