/* queue Demo */
#include <stdlib.h>
#include <stdio.h>

#define HEAD 1
#define TAIL 0
 
// A structure to represent a queue node
struct node
{
    int node_number;
    struct node *next_ptr;
}
*QueueHead, *QueueTail;
 
// Get in line
void enQueue(int NewNodeNumber)
{
    struct node *TempPtr = malloc(sizeof(struct node));
    TempPtr->node_number = NewNodeNumber;

	/* Queue is empty */
	if (QueueHead == NULL)
	{
		TempPtr->next_ptr = NULL;
		QueueHead = QueueTail = TempPtr;
	}
	else
	{
		QueueTail->next_ptr = TempPtr;
		QueueTail = TempPtr;
	}
}
 
// Get out of line
void deQueue(void)
{
	struct node *TempPtr;
	
    // If queue is empty, return 0.
    if (QueueHead == NULL)
	{
		printf("Queue is emtpy\n\n");
		return;
	}
	
    // Store the next pointer
    TempPtr = QueueHead->next_ptr;
	free(QueueHead);
	QueueHead = TempPtr;
}
 
void DisplayQueue(void)
{
	struct node *TempPtr = QueueHead;
	
	while (TempPtr != NULL)
	{
		printf("Queue node %d is at address %p and is pointing to %p\n",
		        TempPtr->node_number, &*TempPtr, TempPtr->next_ptr);
		TempPtr =  TempPtr->next_ptr;
	}
	
	return;
} 
 
int isEmpty(void)
{
	if (QueueHead == NULL)
		return 1;
	else
		return 0;
}

void whosinline(int headortail)
{
    if (isEmpty())
	{
		printf("The queue is empty\n\n");
		return;
	}
    else if (headortail == HEAD)
		printf("The first node is %d at address %p and is pointing to %p\n\n",
		        QueueHead->node_number, &*QueueHead, QueueHead->next_ptr);
	else if (headortail == TAIL)
		printf("The first node is %d at address %p and is pointing to %p\n\n",
		        QueueTail->node_number, &*QueueTail, QueueTail->next_ptr);
}
 
int main(void)
{
	int MenuChoice = 0;
	int NumberToPutInLine = 0;
	enum Menu {ENQUEUE=1, DEQUEUE, HEADVALUE, TAILVALUE, ISEMPTY, DISPLAY, EXIT};
	
	system("clear");
	QueueHead = QueueTail = NULL;
	
	do
	{
		printf("\n\nQueue Menu\n\n"
			   "1. Get in line\n"
			   "2. Get out of line\n"
			   "3. Who's first in line?\n"
			   "4. Who's last in line?\n"
		       "5. Check for empty line\n"
			   "6. Display Line\n"
			   "7. Exit\n\n"
			   "Enter menu choice ");
	
		scanf("%d", &MenuChoice);
		printf("\n\n");
		getchar();
	
		switch (MenuChoice)
		{
			case ENQUEUE :
				printf("Enter a node number to put in line ");
				scanf("%d", &NumberToPutInLine);
				enQueue(NumberToPutInLine);
				DisplayQueue();
				break;
			case DEQUEUE : 
				deQueue();
				DisplayQueue();
				break;
			case HEADVALUE : 
				whosinline(HEAD);
				break;
			case TAILVALUE : 
				whosinline(TAIL);
				break;
			case ISEMPTY : 
				isEmpty() ? printf("The queue is empty\n\n") :
				            printf("The queue is not empty\n\n");
				break;
			case DISPLAY :
				DisplayQueue();
			case EXIT :
				break;
			default : 
				printf("Invalid menu choice\n\n"); 
		}
	}
	while (MenuChoice != EXIT);


    return 0;
}
