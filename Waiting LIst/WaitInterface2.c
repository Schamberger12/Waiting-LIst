#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WaitHead.h"


void doAdd(Queue *q)
{
	/* get group size from input */
	called phoned = IN_HOUSE;
	int size = getPosInt();
	if (size < 1)
	{
		printf("Error: Add command requires an integer value of at least 1\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Add command requires a name to be given\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	

	int truth = doesNameExist(name, q);

	if (truth == 0) {
		printf("Adding In-restaurant group \"%s\" of size %d\n", name, size);
		addToList(q, name, size, phoned);
	}
	else {
		printf("That name is already in the system, please re-enter with a different name\n");
	}


}


void doCallAhead(Queue *q)
{
	/* get group size from input */
	int size = getPosInt();

	if (size < 1)
	{
		printf("Error: Call-ahead command requires an integer value of at least 1\n");
		printf("Call-ahead command is of form: c <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Call-ahead command requires a name to be given\n");
		printf("Call-ahead command is of form: c <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	printf("Adding Call-ahead group \"%s\" of size %d\n", name, size);

	called phoned = CALLED;

	int truth = doesNameExist(name, q); 

	if (truth == 0)
		addToList(q, name, size, phoned);
	else {
		printf("That name is already in the system, please re-enter with a different name\n");
	}
}

void doWaiting(Queue *q)
{
	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: Waiting command requires a name to be given\n");
		printf("Waiting command is of form: w <name>\n");
		printf("  where: <name> is the name of the group that is now waiting\n");
		return;
	}

	int truth = doesNameExist(name, q);
	if (truth == 1) {
		printf("Call-ahead group \"%s\" is now waiting in the restaurant\n", name);
		updateStatus(q, name);
	}
	else {
		printf("There is no such party, please try again\n");
	}

	return;


}

void doRetrieve(Queue *q)
{
	/* get table size from input */
	int size = getPosInt();
	if (size < 1)
	{
		printf("Error: Retrieve command requires an integer value of at least 1\n");
		printf("Retrieve command is of form: r <size>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		return;
	}
	clearToEoln();
	printf("Retrieve (and remove) the first group that can fit at a table of size %d\n", size);

	char* temp = retrieveAndRemove(size, q);

	if (temp == NULL) {
		printf("There are no groups in-house that can currently fit that size\n");
		return;
	}

	else {
		printf("%s, your table is ready, bon appetit!\n", temp);
	}
	return;


}

void doList(Queue *q)
{
	/* get group name from input */
	char *name = getName();
	if (NULL == name)
	{
		printf("Error: List command requires a name to be given\n");
		printf("List command is of form: l <name>\n");
		printf("  where: <name> is the name of the group to inquire about\n");
		return;
	}

	int truth = doesNameExist(name, q);
	if (truth == 0) {
		printf("There is no group with that name, please try again\n");
		return;
	}

	else {
		printf("Group \"%s\" is behind the following groups\n", name);
		int groupNums = countGroupsAhead(q, name);
		printf("There are %d groups ahead of %s\n", groupNums - 1, name);

		displayGroupSizeAhead(q, groupNums);


	}




}

void doDisplay(Queue *q)
{
	clearToEoln();
	printf("Display information about all groups\n");

	displayListInformation(q);
	return;
}