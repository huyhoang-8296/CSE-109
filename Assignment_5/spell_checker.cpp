// Huy Hoang
// CSE 109 
// Assignment 5

#include "hashtable.h"
#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char* argv[]){
	// If there are more than 2 command argc => error
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
	input_file.open(filename);
	words.open(filename2);

	// dictionary is the hash table for the file words.txt which has all the words needed to compare while s is our sample_text.txt or speech.txt
	HashTable dictionary(88985);
	HashTable s(100);
	string vocab, word_check, temp;

	while (!words.eof()){
		words >> vocab;		
		dictionary.hashInsert(vocab);
	}
	// search is for the result if each word is spelled correctly or not while line_no is line number, to represent which line the mispelled word is on. len is the length of the word_check
	bool search;
	int line_no = 1;
	int len = 0;
	
	while	(!input_file.eof()){
		input_file >> word_check;		
		// here, since our hashSearch function does not include for case sensitive, I transform all the words to lower case for easier comparasion.
		// I also create a temp and set it equals to word_check as I will be modifying word_check to easier compare and print the original word as temp if I found the misspelled word
		temp = word_check;
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
		
		search = dictionary.hashSearch(word_check);				
		// Print out the result
		if(search == false){
			cout << "Line " << line_no << " " << " : mispelled word - " << temp <<  endl;
		}
	}
	cout << "Spell check completed." << endl;
	return 0;
}