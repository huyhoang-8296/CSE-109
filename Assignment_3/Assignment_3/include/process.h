#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
 	int id;
 	double exec_time;
 	double arrival_time;
} process;

void print_process(process x);
int compare_processes(process x, process y);