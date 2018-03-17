#ifndef WAITHEAD_H

#define WAITHEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int DebugMode;

typedef enum { FALSE = 0, TRUE, NO = 0, YES } boolean;

typedef enum
{
	CALLED = 0,
	IN_HOUSE = 1
}called;

typedef struct Node {

	char *name;
	int size;
	called phoned;
	struct Node *next;

}Node;

typedef struct Queue {

	Node* Head;
	Node* Tail;
}Queue;

void addToList(Queue *q, char* name, int size, called phoned);
int doesNameExist(char* name, Queue *q);
void updateStatus(Queue* q, char* name);
char* retrieveAndRemove(int size, Queue *q);
int countGroupsAhead(Queue *q, int groupNum);
void displayGroupSizeAhead(Queue *q, char* name);
void displayListInformation(Queue *q);
#endif // !WAITHEAD_H