#include "linked_list.h"

int main(){
  node *list_head = NULL;
  FILE *inputfile;
  student s[600];
  student b;
  inputfile = fopen("students.txt", "r");

  if(inputfile == NULL){
    printf("No data");
    exit(1);
  }
  int select = 0;
  int i = 0;
  char option;
  while (!feof(inputfile)) {
    fscanf(inputfile,"%d%s%lf\n", &s[i].id, s[i].name,&s[i].gpa);
    insert_first(&list_head,s[i]);
    i++;  
  }
  printf("Linked list built from file students.txt successfully.\n");
    
  while(select < 5){  
    printf("Select an operation: \n1: Add a new student \n2: Find an existing student \n3: Delete an existing student \n4: Quit\n");
  
    scanf("%d", &select);  
    switch(select){
      case 1:
        printf("Enter the student information (id, gpa, and name): \n");
        scanf("%d\n%lf\n%s",&b.id,&b.gpa,b.name);
        insert_last(&list_head,b);
        printf("Student record inserted succesfully.\n");
        break;
      case 2:
        printf("Enter the student id: ");
        scanf("%d",&b.id);
        if(search(list_head,b) == 1){
          break;
        }
        else{
          printf("Student record not exist.\n");
          exit(1);
        }             
      case 3:
        printf("Enter the student id: ");
        scanf("%d",&b.id);
        if(search(list_head,b) == 1){
          printf("Are you sure you want to delete student record? (Enter y or n):");
          scanf("%c%c",&option,&option);
          if(option == 'y'){
            delete_item(&list_head,b);
          }
          else if(option == 'n'){
            printf("Student record not deleted.\n");
            exit(0);
          }
          else{
            printf("Wrong option.\n");
            exit(1);
          }
        }
        else{
          printf("Student record not exist.\n");
          exit(1);
        }  
        print_list(list_head);
        break;
      case 4:
        printf("Quit.");
        exit(0);
      default:
        printf("Wrong option.");
        exit(0);
        break;
    }
  }
  
  fclose(inputfile);
  return 0;
  } 
