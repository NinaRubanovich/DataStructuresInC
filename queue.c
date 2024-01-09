#include "queue.h"

Queue initQueue(int *ec)
{
	Queue userQueue;
	userQueue.p = malloc(sizeof(QueueStuff));
	Node *dummy = createNode(NULL);
	if (userQueue.p == NULL || dummy == NULL) *ec = 1;
	else
	{
		userQueue.p->head = dummy;
		userQueue.p->tail = dummy;
		dummy->next = NULL;
		userQueue.p->queueSize = 0;
		*ec = 0;

	}

	return userQueue;
}

/* This function inserts an object at the end of a Queue. 
0 is returned on success, and 1 on failure. */ 
int enqueue(void *object, Queue userQueue)
{
	Node *newNode = createNode(object);
	if (newNode == NULL) return 1;
	else
	{
		userQueue.p->tail->next = newNode;
		tail = newNode;
		incrementQueueSize(userQueue);
		return 0;
	}
}

/* This function removes the object at the beginning of the queue. 
0 is returned on success, and 1 on failure. */
int dequeue(Queue userQueue)
{
	if (getSize(userQueue == 0)) return 1; // nothing to remove
	else
	{
		Node *temp = userQueue.p->head->next;
		if (getSize(userQueue) == 1)
		{
			userQueue.p->tail = userQueue.p->head;
			userQueue.p->head->next = NULL;
		}
		else userQueue.p->head->next = userQueue.p->head->next->next;
		free(temp);
		decrementQueueSize(userQueue);
		return 0;

	}

}


void freeQueue(Queue userQueue)
{
	Node *temp = NULL;

	while (userQueue.p->head != NULL)
	{
		temp = userQueue.p->head;
		userQueue.p->head = userQueue.p->head->next;
		free(temp);
	}
	
	free(userQueue.p);


}


// HELPER FUNCTIONS

int getSize(Queue userQueue)
{
	return userQueue->p->queueSize;	
}

/* This functions mallocs and returns a Node pointer */
Node * createNode(void *object)
{
	Node *newNode = malloc(sizeof(Node));
	if (newNode != NULL) newNode->object = object;
	return newNode;

}

void incrementQueueSize(Queue)
{
	userQueue.p->queueSize = getSize(userQueue) + 1;
}


void decrementQueueSize(Queue)
{
	userQueue.p->queueSize = getSize(userQueue) + 1;
}

