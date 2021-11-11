//Matthew Irvine 1001401200
#include <stdio.h>
#include <stdlib.h>
#include "StackLib.h"
void PushSoldSeat(struct snode **StackTop, char RowToAdd, int SeatToAdd)
{
	struct snode *NewNode = malloc(sizeof(struct snode));
    NewNode->SeatNumber = SeatToAdd;
	NewNode->SeatRow = RowToAdd;
	NewNode->next_ptr = NULL;
	
	if (*StackTop == NULL)
	{
		*StackTop = NewNode;
		(*StackTop)->next_ptr = NULL;
	}
	else
	{
		NewNode->next_ptr = *StackTop;
		*StackTop = NewNode;
    }	
	return;
}

void PopTickets(struct snode *StackTop)
{
	if (StackTop == NULL)
	{
		printf("Pop not executed - stack is empty\n\n");
        return;
	}
	
    struct snode *TempPtr;
	while(StackTop != NULL)
	{
		TempPtr = StackTop;
		printf(" ____________\n|            |\n| Seat %c%d    |\n|____________|\n", StackTop->SeatRow, StackTop->SeatNumber);
		//printf("%p, %p\n", StackTop->next_ptr, TempPtr->next_ptr);
		free(StackTop);
		StackTop = TempPtr->next_ptr;
	}
	return;
}
//printf("POP\n");
//printf("TempPtr pointer= %p\n", TempPtr->next_ptr);
//printf("New Node: pointer %p SeatNumber %d SeatRow %c\n", NewNode, NewNode->SeatNumber, NewNode->SeatRow);
