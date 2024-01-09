#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
	void *object;
	struct nodestruct *next;
} Node;

 typedef struct {
    Node *head;
    int stackSize;
 } StackStuff;

  typedef struct {
     StackStuff *p;
} Stack;

Stack initStack(int *);
int push(void*, Stack);
int pop(Stack);
void freeStack(Stack);
int getSize(Stack);
Node * createNode(void *object);
void incrementStackSize(userStack);
void decrementStackSize(userStack);



