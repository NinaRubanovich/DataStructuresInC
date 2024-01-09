#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
	void *object;
	struct nodestruct *next;
} Node;

 typedef struct {
    Node *head;
    Node *tail;
    int queueSize;
 } QueueStuff;

  typedef struct _List {
     QueueStuff *p;
} Queue;

Queue initQueue(int*);
int enqueue(void*, Queue);
int dequeue(Queue);
void freeQueue(Queue);
int getSize(Queue);
Node * createNode(void *object);
void incrementQueueSize(Queue);
void decrementQueueSize(Queue);





