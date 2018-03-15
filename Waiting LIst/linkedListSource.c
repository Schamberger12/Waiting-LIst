#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WaitHead.h"

void addToList(char* name, int size, Queue* q, Node* n, int called ) {
	Node* temp = malloc(sizeof(temp));

	temp->name = name;
	temp->size = size;
	temp->phoned = called;

	if (q->Head == NULL) {
		q->Head = temp;
		q->Tail = temp;
	}

	q->Tail->next = temp;
	q->Tail = temp;

}

int doesNameExist( Queue* q, char* name) 
{

	char nameCheck[30];
	
	if (q->Head == NULL) {
		return 0;
	}

	Node* temp = q->Head;

	while (temp != NULL) 
	{
		if (name == nameCheck)
			return 1;
		temp = temp->next;
	}

	return 0;

}

void updateStatus(Node* p) 

{
	
	//function returns when a person who called ahead arrives to the restuarant

}

Node* retrieveAndRemove(Node* p, char* name, Queue* q) 
{
	if (q->Head == NULL)
		return NULL;

	Node* temp = q->Head;
	q->Head = q->Head->next;

	if (q->Head == NULL)
		q->Tail = NULL;
	return temp;
}

int countGroupsAhead(Node* p, Queue* q) 
{
	int groupNum = 0;

	if (p == NULL || p->next == NULL) {
		return 0;
	}

	Node* temp = p;

	while (temp != NULL) {
		groupNum++;
		temp = temp->next;
	}

	return groupNum;


}

int displayGroupSizeAhead(Node* p, Queue* q) 
{
	int groupSize = 0;

	if (p->next == NULL) {
		return 0;
	}

	groupSize = p->next->size;
	
	return groupSize;
}

void displayListInformation(Node* p, Queue* q) 
{

}



