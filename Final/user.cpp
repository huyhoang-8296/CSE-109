#include "user.h"



User::User(string username, bool user_priv){
	this->username = username; this->user_priv = user_priv;
	this->newPassword();
}

void User::newPassword(){
  // generate a random number between 5 and 10
  int random = rand()%6 + 5;
  char c;
  for (int i= 0; i<random;i++){
  // generate an ASCII code between 33 and 127
    c = (int) (rand()%95) + 33;
    password += c; //concatenate c to password
  }
}

User::User(){
	username = " "; password = " "; user_priv = false;
}
// Getters
string User::getUsername(){return username;}
bool User::getPriv(){return user_priv;}
string User::getPassword(){return password;}

bool User::operator==(User s){
	if(this->username == s.getUsername()){
		return true;
	}
	return false;
}

// Setters
void User::setUsername(string username){
	this->username = username;
}
void User::setPassword(string password){
	this->password = password;
}
void User::setPriv(bool priv){
	this->user_priv = priv;
}
ostream& operator<<(ostream &write, User s){
	write << s.username << " " << s.password << " " << s.user_priv;
	return write;
}
istream& operator>>(istream &read, User &s){
	read >> s.username >> s.password >> s.user_priv;
	return read;
}

