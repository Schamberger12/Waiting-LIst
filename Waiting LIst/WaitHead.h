#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef enum
{
	CALLED = 0,
	IN_HOUSE = 1
}called;

typedef struct Node {

	char *name;
	int size;
	called phoned;
	Node *next;

}Node;

typedef struct Queue {

	Node *Head;
	Node *Tail;

}Queue;

void addToList(Queue *q, char* name, int size, called phoned);
int doesNameExist(char* name, Queue *q);
void updateStatus(Queue* q, char* name);
Node* retrieveAndRemove(int size, Queue *q);
int countGroupsAhead(Queue *q, char* name);
void displayGroupSizeAhead(Queue *q, int n);
void displayListInformation(Queue *q);
