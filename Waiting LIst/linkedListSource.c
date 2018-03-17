#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WaitHead.h"

//addToList takes in all relevant information about the party being added to the list and allocates memory/places node at the end of the linked list
void addToList(Queue *q, char *name, int size, called phoned) {
	
	Node* temp = (Node*)malloc(sizeof(Node));	//malloc! for the node!

	temp->name = name;				//sets the new node's pieces to the information submitted.
	temp->size = size;
	temp->phoned = phoned;
	temp->next = NULL;

	if (q->Head == NULL && q->Tail == NULL) {	//if both the head and the tail of the node are NULL,
		q->Head = q->Tail = temp;				//the node just added is set to both the head and tail
		return;
	}
	
	
	q->Tail->next = temp;			//makes the next node after the tail the new-created node
	
	q->Tail = q->Tail->next;		//moves the tail to the end of the list, making the new node the tail.
	
	return;
}
//searches for a name, returns 1 if found, returns 0 if didn't find
int doesNameExist(char *name, Queue *q)
{
	Node* temp = q->Head;		

	if (temp == NULL) {		//if there's nothing in the list, return 0.
		return 0;
	}


	while (temp != NULL)				//iterate through list until the name is found, if not found then stop iterating
	{
		if (DebugMode == TRUE) {
			if (temp->phoned == IN_HOUSE) {
				printf("name: %s, size: %d, In House\n", temp->name, temp->size);

			}
			else {
				printf("name: %s, size: %d, called in\n", temp->name, temp->size);
			}
			
		}
		if (strcmp(name, temp->name) == 0)
			return 1;
		temp = temp->next;
	}
		
	return 0;		//return 0 if name not found in entire list.
		
}
//updates the status of a person who called in to being in-house
void updateStatus(Queue *q, char *name)
{
	Node *temp = q->Head;		

	if (temp == NULL) {					//if the list is empty, might as well just return.
		printf("List is empty\n");
		return;
	}


	while (temp != NULL)				//iterates through list until name is found
	{
		if (DebugMode == TRUE) {
			if (temp->phoned == IN_HOUSE) {
				printf("name: %s, size: %d, In House\n", temp->name, temp->size);

			}
			else {
				printf("name: %s, size: %d, called in\n", temp->name, temp->size);
			}

		}
		if (strcmp(name, temp->name) == 0) {
			temp->phoned = IN_HOUSE;	//updates name.
			return;
		}
		temp = temp->next;	
	}

	return;		//returns if name is not found



}
//retrieveAndRemove iterates throughout the list until a party of size requested and that is in the restuarant is found, else it returns empty
char* retrieveAndRemove(int size, Queue *q)
{
	Node* temp = q->Head;
	Node* temp2 = q->Head;
	char* name = NULL;

	if (temp == NULL) {		//if list is empty, then returns immediately
		return NULL;
	}

	if (temp->size == size && temp->phoned == IN_HOUSE) {	//base case to go through the linked list, if the head is available to be seated then uses them
		name = temp->name;		//name of party available is held
		temp2 = temp;			//sets a temporary node to the node to be removed from the list
		temp = temp->next;		//temp goes to the next node
		q->Head = temp;			//sets the 2nd node in the list to be the new head
		free(temp2);			//de-allocates the node that held the party availble
		return name;			//returns just the name to be used in a small printf statement after retrieveAndRemove exits
	}
	temp2 = temp2->next;	//if the head isn't the node to be returned, then we hold 2 consecutive nodes in our view to easily remove and restitch the linked list
	while (temp != NULL) {	//iterates through linked list
		if (DebugMode == TRUE) {
			if (temp->phoned == IN_HOUSE) {
				printf("name: %s, size: %d, In House\n", temp->name, temp->size);

			}
			else {
				printf("name: %s, size: %d, called in\n", temp->name, temp->size);
			}

		}
		if (temp2->size == size && temp2->phoned == IN_HOUSE) {//if found, same proceure as before
			name = temp2->name;
			temp->next = temp2->next;
			free(temp2);
			return name;
		}
		temp2 = temp2->next;	
		temp = temp->next;
	}
	

	return NULL;		//return NULL if cannot find
}
//counts how many groups are ahead of the group specified
int countGroupsAhead(Queue* q, char* name)
{
	int groupNum = 0;
	Node* temp = q->Head;		//sets temp node to head of list

	if (temp == NULL) {		
		return 0;
	}
	//while loop simply iterates through the list and adds 1 to the variable groupNum every time move to next node
	while (temp != NULL) {
		if (DebugMode == TRUE) {
			if (temp->phoned == IN_HOUSE) {
				printf("name: %s, size: %d, In House\n", temp->name, temp->size);

			}
			else {
				printf("name: %s, size: %d, called in\n", temp->name, temp->size);
			}

		}
		groupNum++;						
		if (strcmp(name, temp->name) == 0)
			return groupNum;
		temp = temp->next;
	}

	return groupNum;


}
//displays all the group info from the top of the list until the person inquired about
void displayGroupSizeAhead(Queue* q, int groupNum)
{

	Node* temp = q->Head;
	int i = 0;

	for (i = 0; i < groupNum - 1 ; i++) {					//this time uses a for loop to allow for us to use the extracted number GroupNum to continue until the end
		printf("%s, party of %d\n", temp->name, temp->size);
		temp = temp->next;
	}
	
	return;
}

//shows the list in entirety
void displayListInformation(Queue* q)
{
	Node* temp = q->Head;
	int t = 0;

	if (temp == NULL)
		printf("There is no one in house");
	while (temp != NULL) {
		printf("%s, party of %d", temp->name, temp->size);
		if (temp->phoned == IN_HOUSE)
			printf(" In House\n");
		else
			printf(" called in\n");
		temp = temp->next;
	}
	return;


}





