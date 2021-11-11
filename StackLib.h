//Matthew Irvine 1001401200
#ifndef _STACKLIB_H
#define _STACKLIB_H
struct snode
{
	int SeatNumber;
	char SeatRow;
	struct snode *next_ptr;
};
void PushSoldSeat(struct snode **, char , int );
void PopTickets(struct snode *);
#endif
