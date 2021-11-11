//Matthew Irvine ListLib.h file
#ifndef _LISTLIB_H
#define _LISTLIB_H
struct node 
{
	char SeatRow;
	int SeatNumber;
	struct node *next_ptr;
};
void AddSoldSeatToList(struct node **,char,int);
void PrintTickets(struct node *);
#endif
