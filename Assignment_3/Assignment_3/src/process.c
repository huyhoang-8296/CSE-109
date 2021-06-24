#include "process.h"

void print_process(process x){
	
	printf("%d\t%.0f\t\t%.0f\t\t", x.id, x.exec_time, x.arrival_time);
}

int compare_processes(process x, process y){
	if(x.id == y.id){
		return 0;
	}
	return 1;
}