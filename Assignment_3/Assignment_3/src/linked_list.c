#include "linked_list.h"


void enqueue(queue **front, queue **back, process item){
		queue *new_element = (queue*) malloc(sizeof(queue));
		new_element->process_data = item;
		new_element->prev = NULL;
		new_element->next = NULL;
		if((*back == NULL)){
			*back = new_element;
			*front = new_element;
			return;
		}
		new_element->next = (*back);
		(*back)->prev = new_element;

		*back = new_element;
}
process dequeue(queue **front, queue **back){
	queue *second_last;
	process hello;
  if(*front == NULL){//empty queue
		printf("There's no process to be deleted.");
		return hello;// this return statement was missing
	}
	if((*front)->prev == NULL){ // queue with one element - it was front->next == NULL which is always NULL
		hello = (*front)->process_data;
		free (*front);
		*front = NULL;
		*back = NULL;
		return hello;
	}
	second_last = *front;

	hello = second_last->process_data;
	(*front)->prev->next = NULL;
	*front = (*front)->prev;
	free(second_last);
	return hello;

}

int search(queue *front, process item){
	if(front == NULL)
    return -1;
  else{
    queue *current = front;
    while(current != NULL){
    if (compare_processes(current->process_data, item) == 0) {
      printf("Process record found.\n");
      return 1;
    }
    current = current->next;
    }
    return -1;
  }
}

void print_queue(queue *front){
	queue *current = front;
	while(current != NULL){
		print_process(current->process_data);
		current = current->next;
	}
}

int size(queue *front){
	int size = 0;
	queue *current = front;
	while(current != NULL){
		current = current->next;
		size++;
	}
	return size;
}