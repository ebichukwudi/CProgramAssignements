/* SortedArrayList.c 
 create a list from randomly generated array of numbers
 and subsequently sort them and print them 5 rows at a time on the screen*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
 
//declares the struct to store the list
typedef struct list { int data; struct list * next; }list;

//function definition to check if the list is empty.
int IsEmpty(const list *l)
{
	return (l == NULL);
}

//function definition to create the list
list* CreateList(int d)
{
	list* head = malloc(sizeof(list));
	head->data = d;
	head->next = NULL;
	return head;
}

//function definition to add a node in front of list
list * AddToFront(int d, list * h)
{
	list * head = CreateList(d);
	head->next = h;
	return head;
}

//function definition to create a list from array
list * ArrayToList(int d[], int size)
{
	list * head = CreateList(d[0]);
	int i;

	for (i = 1; i < size; i++)
	{
		head = AddToFront(d[i], head);

	}

	return head;
}

// function to insert a new_node in a list. 
void SortedInsert(list ** head, list* newNode)
{
	list * current;

	/* special case for the head end */

	if (*head == NULL || (*head)->data >= newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		/* locate the node before the point of insertion */
		current = *head;

		while (current->next != NULL && current->next->data < newNode->data)
		{
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}
}

//function to sort a singly linked list using insertion sort
void SortList(list ** head)
{
	// initialise sorted linked list
	list * sortedList = NULL;

	//tranverse the given linked list and insert every node to sortedList

	list * current = *head;

	while (current != NULL)
	{
		//store next for next iteration
		list * next = current->next;

		//insert current in sorted linked list
		SortedInsert(&sortedList, current);

	    //update current
		current = next;
	}

	//update the head to point to sorted linked list
	*head = sortedList;
}

//function definition to print values of singly link list in rows of 5 on the screen.
void PrintList(list *h, char * title)
{
	printf("%s\n", title);
	int i = 0;
	while (h != NULL)
	{
		printf("%5d", h->data);
		h = h->next;
		++i;
		if (i % 5 == 0)
		{
			printf("\n");
		}
	}
}

int main(void)
{
	srand(time(NULL)); /* randomize */

	int ArrayofNumbers[100];

	//populate the array with random generated value.
	int j; // to store the temp generated number.
	int i; // the counter

	for (i = 0; i < 100; i++)
	{
		j = rand() % 100;
		ArrayofNumbers[i] = j;
	}

	list* head = NULL;
	// transform the array of numbers to list.
	head = ArrayToList(ArrayofNumbers, 100);
	
	//print the value without sorting
	PrintList(head, "Array of 100 numbers");

	//sort the list
	SortList(&head);

	//print the values of the sorted list
	PrintList(head, "Array of 100 numbers after sorting");

	getchar();

	return 0; /* indicates successful termination */

} /* end main */

