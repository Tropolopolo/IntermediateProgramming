/* stack Demo */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// A structure to represent a stack node
struct node
{
    int node_number;
    struct node *next_ptr;
}
*StackTop;
 
int isEmpty(void)
{
	if (StackTop == NULL)
		return 1;
	else
		return 0;
}
 
void push(int NodeNumber)
{
    struct node *NewNode = malloc(sizeof(struct node));
    NewNode->node_number = NodeNumber;
	
	if (StackTop == NULL)
	{
		StackTop = NewNode;
		StackTop->next_ptr = NULL;
	}
	else
	{
		NewNode->next_ptr = StackTop;
		StackTop = NewNode;
    }

	printf("Stack node %d pushed with address %p and is pointing to %p\n",
		   StackTop->node_number, &*StackTop, StackTop->next_ptr);	
	
}
 
void pop(void)
{
	if (StackTop == NULL)
	{
		printf("Pop not executed - stack is empty\n\n");
        return;
	}
	
    struct node *TempPtr = StackTop;
    StackTop = TempPtr->next_ptr;

	printf("Stack node %d popped from address %p that was pointing to %p\n",
		   TempPtr->node_number, &*TempPtr, TempPtr->next_ptr);	

    free(TempPtr);
	return;
 }
 
void peek(void)
{
    if (isEmpty())
        printf("The stack is empty\n\n");
    else
		printf("The top node has a value of %d at address %p and is pointing to %p\n\n",
		        StackTop->node_number, &*StackTop, StackTop->next_ptr);
}

void DisplayStack(void)
{
	struct node *TempPtr = StackTop;
	
	while (TempPtr != NULL)
	{
		printf("Stack node %d is at address %p and is pointing to %p\n",
		        TempPtr->node_number, &*TempPtr, TempPtr->next_ptr);
		TempPtr =  TempPtr->next_ptr;
	}
	
	return;
}
 
int main(void)
{
	int MenuChoice = 0;
	int NodeNumberToPush = 0;
	enum Menu {PUSH=1, POP, PEEK, ISEMPTY, DISPLAY, EXIT};
	
	system("clear");
	
	StackTop = NULL;
	
	do
	{
		printf("\n\nStack Menu\n\n"
			   "1. Push\n"
			   "2. Pop\n"
			   "3. Peek\n"
		       "4. Check for empty\n"
			   "5. Display Stack\n"
			   "6. Exit\n\n"
			   "Enter menu choice ");
	
		scanf("%d", &MenuChoice);
		printf("\n\n");
		getchar();
	
		switch (MenuChoice)
		{
			case PUSH :
				printf("Enter a node number to push ");
				scanf("%d", &NodeNumberToPush);
				push(NodeNumberToPush);
				break;
			case POP  : 
				pop();
				break;
			case PEEK : 
				peek();
				break;
			case ISEMPTY : 
				isEmpty() ? printf("The stack is empty\n\n") :
				            printf("The stack is not empty\n\n");
				break;
			case DISPLAY :
				DisplayStack();
			case EXIT :
				break;
			default : 
				printf("Invalid menu choice\n\n"); 
		}
	}
	while (MenuChoice != EXIT);
	
    return 0;
}
