// Huy Hoang
// CSE 109 
// Assignment 2

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{ START, IDENTIFIER, NUMBER, BUILDING_IDENTIFIER, BUILDING_NUMBER} state;

state transition(state current_state, char current_char);


int main(){
  char filename[20] = "sample.txt";
  FILE *inputfile;  
  char word[2048];

  inputfile = fopen("sample.txt", "r");
  if (inputfile == NULL){
    printf("Error: Cannot open file %s for reading.", filename);
    exit(1);
  }
   
  int num_id = 0, num_number = 0, num_key = 0;
  int index = 0;
  state current_state = START;
  char current_char = getc(inputfile);
 
  while(current_char != EOF){           
    current_state = transition(current_state, current_char);       
    if(current_char != ' ' && current_char != '\t' && current_char != '\n'){
      word[index++] = current_char;
    }
    
    if(current_state == IDENTIFIER){   
      word[index] = '\0';              
      if(strcmp(word,"auto") == 0 || strcmp(word,"break") == 0 || strcmp(word,"case") == 0 || strcmp(word,"char") == 0 || strcmp(word,"const") == 0 || strcmp(word,"continue") == 0 || strcmp(word,"default") == 0 || strcmp(word,"do") == 0 || strcmp(word,"double") == 0 || strcmp(word,"else") == 0 || strcmp(word,"enum") == 0 || strcmp(word,"extern") == 0 || strcmp(word,"float") == 0 || strcmp(word,"goto") == 0 || strcmp(word,"void") == 0 || strcmp(word,"for") == 0 || strcmp(word,"if") == 0 || strcmp(word,"int") == 0 || strcmp(word,"long") == 0 || strcmp(word,"switch") == 0 || strcmp(word,"short") == 0 || strcmp(word,"register") == 0 ||  strcmp(word,"signed") == 0 || strcmp(word,"return") == 0 || strcmp(word,"volatile") == 0 || strcmp(word,"sizeof") == 0 || strcmp(word,"static") == 0 || strcmp(word,"typedef") == 0 || strcmp(word,"unsigned") == 0 || strcmp(word,"struct") == 0 || strcmp(word,"union") == 0 || strcmp(word,"while") == 0 ){
        printf("%s - keyword\n", word);
        num_key++;        
      }
      else{        
        printf("%s - identifier\n",word);
        num_id++;
      }      
      current_state = START;
      index = 0;
    }
    else if (current_state == NUMBER){
      word[index] = '\0';           
      num_number++;
      printf("%s - number\n", word);                   
      current_state = START;
      index = 0;
    }  
     
    current_char = getc(inputfile);
  }
   
  printf("Number of identifiers: %d\n", num_id);
  printf("Number of keywords: %d\n", num_key);
  printf("Number of numbers: %d\n", num_number);
  fclose(inputfile);
  return 0;
}

state transition(state current_state, char current_char){
  if(isdigit(current_char) && current_state == START){
    current_state = BUILDING_NUMBER;
    return current_state;
  }
  else if(isdigit(current_char)  && current_state == BUILDING_NUMBER){
    current_state = BUILDING_NUMBER;
    return current_state;
  } 
  else if(current_state == START && isalpha(current_char)){
    return current_state = BUILDING_IDENTIFIER;
  }  
  else if(current_state == BUILDING_IDENTIFIER && ((isalpha(current_char) || isdigit(current_char) || current_char == '_'))){
    return current_state;
  }
  else if(current_state == BUILDING_NUMBER && isspace(current_char)){
    return current_state = NUMBER;
  }
  else if(current_state == BUILDING_IDENTIFIER && isspace(current_char)){
    return current_state = IDENTIFIER;
  }
  else if(current_state == START && (isspace(current_char) || current_char == '\t')){
    return current_state = START;
  }
}
