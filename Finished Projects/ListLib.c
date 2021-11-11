// Matthew Irvine ListLib.c file
#include "ListLib.h"
#include <stdio.h>
#include <stdlib.h>
void AddSoldSeatToList(struct node **LinkedListHeadptr,char RowToAdd,int SeatToAdd)
{
	
	struct node *TempPtr, *NewNode;
    
	NewNode = malloc(sizeof(struct node));
    //NewNode->node_number = NewNodeNumber;  I don't think this will be used for this program.
	NewNode->SeatNumber = SeatToAdd;
	NewNode->SeatRow = RowToAdd;
	NewNode->next_ptr = NULL;

    /* Linked list is empty so point head at new node */
	if (*LinkedListHeadptr == NULL)
    {
		*LinkedListHeadptr = NewNode;
	}
	else
	{
		TempPtr = *LinkedListHeadptr;
	
		/* Traverse the linked list to find the end node */
		while (TempPtr->next_ptr != NULL)
			TempPtr = TempPtr->next_ptr;
	
		/* Change end node to point to new node */
		TempPtr->next_ptr = NewNode;
	}
}

void PrintTickets(struct node *LinkedListHead)
{
	struct node *TempPtr;
    TempPtr = LinkedListHead;

	/* Linked list is empty */
    if (TempPtr == NULL)
    {
		return;
    }

	/* Traverse the linked list and display the node number */
    while (TempPtr != NULL)
    {
		printf(" ____________\n|            |\n| Seat %c%d    |\n|____________|\n", TempPtr->SeatRow, TempPtr->SeatNumber);
		TempPtr = TempPtr->next_ptr;
    }
}
