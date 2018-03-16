#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WaitHead.h"

void addToList(Queue* q, char* name, int size, called phoned) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->name = name;
	temp->size = size;
	temp->phoned = phoned;

	if (q->Head == NULL) {
		q->Head = temp;
		q->Tail = temp;
	}

	q->Tail->next = temp;
	q->Tail = temp;

}

int doesNameExist(char* name, Queue* q) 
{
	Node* temp = q->Head;
	
	if (temp == NULL) {
		return 0;
	}


	while (temp != NULL) 
	{
		if (temp->name == name)
			return 1;
		temp = temp->next;
	}

	return 0;

}

void updateStatus(Queue* q, char* name) 
{
	Node* temp = q->Head;

	if (temp == NULL) {
		printf("List is empty\n");
		return;
	}


	while (temp != NULL)
	{
		if (temp->name == name) {
			temp->phoned = IN_HOUSE;
			return;
		}
		temp = temp->next;
	}

	return;

}

Node* retrieveAndRemove(int size, Queue* q)
{
	
	Node* temp = q->Head;

	while ((temp->next != NULL) && (temp->next->size != size) && (temp->next->next->phoned != IN_HOUSE)) {
		temp = temp->next;
	}
	if (temp == NULL) {
		return NULL;
	}

	return temp;
}

int countGroupsAhead(Queue* q, char* name) 
{
	int groupNum = 0;
	Node* temp = q->Head;

	if (temp == NULL) {
		return 0;
	}

	while (temp->name != name) {
		groupNum++;
		temp = temp->next;
	}

	return groupNum;


}

void displayGroupSizeAhead(Queue* q, int n) 
{
	
	Node* temp = q->Head;
	int i;

	for (i = 0; i < n; i++) {
		printf("%d: %s, party of %d\n", i+1, temp->name, temp->size);
	}
	
	return;
}

void displayListInformation(Queue* q) 
{
	Node* temp = q->Head;
	int i;

	while (temp != NULL) {
		printf("%d: %s, party of %d", i+1, temp->name, temp->size);
		if (temp->phoned == IN_HOUSE)
			printf("In House\n");
		else {
			printf("Called in\n");
		}
		i++;
		temp = temp->next;
	}
	return;


}



