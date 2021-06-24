#include "linked_list.h"

process process_arrived(int time){
	process p;
	p.id = 0;p.arrival_time=0; p.exec_time=0;
		switch(time){
		case 15:p.id = 1; p.arrival_time = 15; p.exec_time = 100;
			break;
		case 25:p.id = 2; p.arrival_time = 25; p.exec_time = 50;
			break;
		case 50:p.id = 3; p.arrival_time = 50; p.exec_time = 180;
			break;
		case 75:p.id = 4; p.arrival_time = 75; p.exec_time = 10;
			break;
		case 100:p.id = 5; p.arrival_time = 100; p.exec_time = 75;
			break;
		case 125:p.id = 6; p.arrival_time = 125; p.exec_time = 35;
			break;
		case 130:p.id = 7; p.arrival_time = 130; p.exec_time = 200;
			break;
		}
	return p;
}

int main(){
	process test, current_process;
	current_process.id = 0;
	int current_exec = 0;
	queue *front = NULL, *back = NULL;
	int complete = 0;
	int wait_time = 0;
	
	printf("ID\tTime\tArrived\tCompleted\tWaiting\n");
	for(int time = 0; time < 666; time++){
		test = process_arrived(time);	
		if(test.id != 0){	
			enqueue(&front,&back,test);	
		}
		if(current_process.id != 0){
			if(current_exec > 0){
				current_exec--;
			}
			if(current_exec == 0){
				complete = time;
				wait_time = complete - current_process.exec_time - current_process.arrival_time;
				print_process(current_process);
				printf("%d\t\t\t%d\n",complete,wait_time);
				current_process.id = 0;
			}	
		}
		if(current_process.id == 0){
			if(front != NULL){
				current_process = dequeue(&front,&back);				
				current_exec = current_process.exec_time;
			}
		}		
	}	
	
	return 0;
}
