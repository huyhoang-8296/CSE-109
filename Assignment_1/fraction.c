// Huy Hoang
// CSE 109 
// Assignment 1
#include <stdio.h>

typedef struct{
  int numerator;
  int denominator;
} fraction;

void add_fractions(fraction a, fraction b, fraction *result);
void multiply_fractions(fraction a, fraction b, fraction *result);
void print_fraction(fraction a);
fraction get_fraction(fraction a);
int find_gcd(int a, int b);
void reduce_fraction(fraction *a);
void invert_fraction(fraction *a);

int main(){
  fraction a, b, result;
  char c, choice;
  
  do{        
    a = get_fraction(a);
    b = get_fraction(b);     
    printf("Select an operation (+,-,*,/) ");
    do{
      
      scanf("%c%c", &c,&c);
      if(c == '+')
      {
        add_fractions(a, b, &result);         
        
        printf("%d/%d + %d/%d = ",a.numerator,a.denominator,b.numerator,b.denominator);
        reduce_fraction(&result);
        print_fraction(result);        
      } 
      else if(c == '*')
      {
        multiply_fractions(a, b, &result);
        printf("%d/%d * %d/%d = ",a.numerator,a.denominator,b.numerator,b.denominator); 
        reduce_fraction(&result);
        print_fraction(result);       
      }
      else if(c == '-')
      {
        printf("%d/%d - (%d/%d) = ",a.numerator,a.denominator,b.numerator,b.denominator);
        if((a.numerator > 0 && b.numerator > 0)){
          b.numerator = b.numerator * (-1);
          add_fractions(a, b, &result);
          reduce_fraction(&result);
        }
        else if(a.numerator < 0 && b.numerator > 0){
          a.numerator = a.numerator * (-1);
          add_fractions(a,b,&result);
          reduce_fraction(&result);
          printf("-");
        }   
        else if((a.numerator > 0 && b.numerator < 0)){
          b.numerator = b.numerator * (-1);
          add_fractions(a, b, &result);
          reduce_fraction(&result);
        }   
        else if(a.numerator < 0 && b.numerator < 0){
          a.numerator = a.numerator * (-1);
          b.numerator = b.numerator * (-1);
          add_fractions(a, b, &result);
          reduce_fraction(&result);
          printf("-");
        }
        print_fraction(result);        
      }
      else if(c == '/')
      {
        printf("%d/%d / (%d/%d) = ",a.numerator,a.denominator,b.numerator,b.denominator); 
        invert_fraction(&b);
        multiply_fractions(a, b, &result);        
        reduce_fraction(&result);       
        print_fraction(result);     
      }
      else{
        printf("Invalid operation – must be (+,-,*, or /) "); 
        //printf("Select an operation (+,-,*,/) ");
      }
    }while(!(c == '+' || c == '-' || c == '*' || c == '/' ));
        
    
    printf("Do you want to perform another operation? (y/n) ");
    scanf("%c%c", &choice, &choice);
  }while(choice == 'y');
  
  return 0;
}

fraction get_fraction(fraction a)
{
  int num_1, num_2;
    
  printf("Enter a common fraction as two integers separated by a slash: ");
  scanf("%d/%d", &num_1, &num_2);
  a.numerator = num_1;
  a.denominator = num_2;
  if(a.denominator <= 0){
    printf("Invalid input - denominator must be positive. \n");
    get_fraction(a);
  }
  else{
    return a;
  } 
}

void add_fractions(fraction a, fraction b, fraction *result){   
    if(a.denominator == b.denominator){
      result->numerator = a.numerator + b.numerator;
      result->denominator = a.denominator;
    }
    else{
      result->numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
      result->denominator = a.denominator * b.denominator;
    }
}

void print_fraction(fraction a){
  if(a.denominator == 1){
    printf("%d \n",a.numerator);
  }
  else if(a.numerator != a.denominator){
    printf("%d/%d \n",a.numerator,a.denominator);
  }
  else if(a.numerator == a.denominator){
    printf("1 \n");
  }
  else{
    printf("%d \n", a.numerator);
  }
}

void multiply_fractions(fraction a, fraction b, fraction *result){
  result->numerator = a.numerator * b.numerator;
  result->denominator = a.denominator * b.denominator;
}

void invert_fraction(fraction *a){
  fraction temp = *a;
  temp.numerator = a->denominator;
  temp.denominator = a->numerator;
  a->numerator = temp.numerator;
  a->denominator = temp.denominator;
}

int find_gcd(int a, int b){
  int gcd, remainder;
  while (a != 0){
    remainder = b % a;
    b = a;
    a = remainder;
  }
  gcd = b;
  return gcd;
}

void reduce_fraction(fraction *a){
  int gcd; 
  gcd = find_gcd(a->numerator, a->denominator);
  a->numerator = a->numerator / gcd;
  a->denominator = a->denominator / gcd;
  if(a->denominator < 0){
    a->denominator = a->denominator * (-1);
    a->numerator = a->numerator * (-1);
  }  
}