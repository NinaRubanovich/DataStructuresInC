#include "stack.h"


Stack initStack(int *ec)
{
	Stack userStack;
	userStack.p = malloc(sizeof(StackStuff));
	Node *dummyNode = createNode(NULL);
	if (userStack.p == NULL || dummyNode == NULL) *ec = 1;
	else
	{
		userStack.p->head = dummyNode;
		dummyNode->next = NULL;
		userStack.p->stackSize = 0;
		*ec = 0;
	}
	return userStack;
}


int push(void *object, Stack userStack)
{
	Node *newNode = createNode(object);
	if (newNode == NULL) return 1;
	else
	{
		if (getSize(userStack) == 0)
		{
			userStack.p->head->next = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = userStack.p->head->next;
			userStack.p->head->next = newNode;
		}
		incrementStackSize(userStack);
		return 0;
	}

}


int pop(Stack userStack)
{
	if (getSize(userStack) == 0) return 1; // no items to remove
	else
	{
		Node *temp = userStack.p->head->next;

		if (getSize(userStack) == 1) userStack->head->next = NULL;
			
		else userStack->head->next = userStack.p->head->next->next;

		free(temp);
		decrementStackSize(userStack);
		return 0;
	}

}


void freeStack(Stack userStack)
{
	Node *temp = NULL;

	while (userStack.p->head != NULL)
	{
		temp = userStack.p->head;
		userStack.p->head = userStack.p->head->next;
		free(temp);
	}
	
	free(userStack.p);

}


int getSize(Stack userStack)
{
	return userStack.p->stackSize;	
}


// HELPER FUNCTIONS

/* This functions mallocs and returns a Node pointer */
Node * createNode(void *object)
{
	Node *newNode = malloc(sizeof(Node));
	if (newNode != NULL) newNode->object = object;
	return newNode;

}


void incrementStackSize(userStack)
{
	userStack.p->stackSize = getSize(userStack) + 1;
}


void decrementStackSize(userStack)
{
	userStack.p->stackSize = getSize(userStack) - 1;

}