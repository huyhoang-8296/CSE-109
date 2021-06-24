#include "process.h"

typedef struct queue_node{
 	process process_data;
 	struct queue_node *next;
 	struct queue_node *prev;
} queue;

void enqueue(queue **front, queue **back , process item);
process dequeue(queue **front, queue **back);
int search(queue *head, process item);
void print_queue(queue *head);
int size(queue *head);

