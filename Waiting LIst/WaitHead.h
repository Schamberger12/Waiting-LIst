#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {

	char* name;
	int size;
	enum status { here = 1, called = 0 };
	Node *next;

}Node;

typedef struct Queue {

	Node *Head;
	Node *Tail;

}Queue;