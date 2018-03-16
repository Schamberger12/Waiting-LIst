#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum
{
	CALLED = 0,
	IN_HOUSE = 1
}called;

typedef struct Node {

	char* name;
	int size;
	called phoned;
	Node *next;

}Node;

typedef struct Queue {

	Node *Head;
	Node *Tail;

}Queue;