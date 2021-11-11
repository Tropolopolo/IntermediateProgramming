//Matthew Irvine 1001401200
#ifndef _QUEUELIB_H
#define _QUEUELIB_H
struct qnode
{
	int SeatNumber;
	char SeatRow;
	struct qnode *next_ptr;
};
void EnqueueSoldSeat(struct qnode **, struct qnode **, char , int );
void DequeueTickets(struct qnode *);
#endif
