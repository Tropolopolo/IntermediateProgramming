//Matthew Irvine 1001401200
#include <stdio.h>
#include <stdlib.h>
#include "QueueLib.h"
void EnqueueSoldSeat(struct qnode **QueueHead, struct qnode **QueueTail, char RowToAdd, int SeatToAdd)
{
	struct qnode *TempPtr = malloc(sizeof(struct qnode));
    TempPtr->SeatNumber = SeatToAdd;
	TempPtr->SeatRow = RowToAdd;
	TempPtr->next_ptr = NULL;

	if (*QueueHead == NULL)
	{
		TempPtr->next_ptr = NULL;
		*QueueHead = *QueueTail = TempPtr;
	}
	else
	{
		(*QueueTail)->next_ptr = TempPtr;
		*QueueTail = TempPtr;
	}
	
}

void DequeueTickets(struct qnode *QueueHead)
{
	struct qnode *TempPtr = QueueHead;
	
    // If queue is empty, return 0.
    while (QueueHead != NULL)
	{
		printf(" ____________\n|            |\n| Seat %c%d    |\n|____________|\n", QueueHead->SeatRow, QueueHead->SeatNumber);
		TempPtr = QueueHead->next_ptr;
		free(QueueHead);
		QueueHead = TempPtr;
	}
	
    // Store the next pointer
    
}
