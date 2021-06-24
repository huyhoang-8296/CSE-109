#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class User{
	private:
		string username;
		string password;
		bool user_priv;

	public:
		// Default contructor
		User();
		// Constructor
		User(string username, bool user_priv);
		// Getters	
		string getUsername();
		bool getPriv();
		string getPassword();
		// Setters
		void setUsername(string username);
		void setPassword(string password);
		void setPriv(bool priv);
		
		void newPassword();
		bool operator==(User s);		
		friend ostream& operator<<(ostream &write, User s);
		friend istream& operator>>(istream &read, User& s);		
};

