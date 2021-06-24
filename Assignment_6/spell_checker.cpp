// Huy Hoang
// CSE 109 
// Assignment 6

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Wrong command line." << endl;
		exit(0);
	}
	// Declare the infile for sample_text or speech.txt and a seperate infile for words.txt with their names
	ifstream input_file, words;
	char filename[20] = "sample_text.txt";
	char filename2[20] = "words.txt";

	// Check for the command line if input in proper names
	if(strcmp(argv[1],filename) != 0){
		cout << "Wrong file name" << endl;
		exit(0);
	}
	// Open the sample_text.txt and words.txt file
	input_file.open(filename);
	words.open(filename2);
	// Declare the unordered map <string, string> dictionary that will include all the words that we need to compare with, and hashIterator is a variable for later when we check if the word is misspelled
	unordered_map<string, string> dictionary;
	unordered_map<string, string>::iterator hashIterator;
	// string vocab will be the input for dictionary, word_check for sample_text.txt and temp will be used to store the original word before transform, and line_no is line number.
	string vocab, word_check, temp;
	int line_no = 0;

	while (!words.eof()){
		words >> vocab;	
		dictionary[vocab] = vocab;
	}

	while (!input_file.eof()){
		input_file >> word_check;	
		temp = word_check;

		// Transform the all the words to lower case because we are using case insensitive.
		transform(word_check.begin(), word_check.end(), word_check.begin(), ::tolower);

		// Here I check whether the parsing character has punctuation or not
		for (int i = 0, len = word_check.size(); i < len; i++){         
			if (ispunct(word_check[i])){ 
				if(word_check[i] == '-'){
					break;
				}
				word_check.erase(i--, 1); 
				len = word_check.size(); 
			} 
		}	
		// This if statement is to look for the newline, if the input_file goes to a newline, we increment the line number
		if(input_file.peek() == '\n'){
			line_no++;
		}		
		// hashIterator will return the string if it is not in the dictionary.
		hashIterator = dictionary.find(word_check);
		
		if(hashIterator == dictionary.end()){
 			cout << "Line " << line_no << " " << " : mispelled word - " << temp <<  endl;
		}
	}	
	return 0;
}


