//Matthew Irvine 1001401200
#ifndef _BSTLIB_H
#define _BSTLIB_H
struct BSTnode
{
	char MovieTheaterName[50];
	char MovieTheaterZip[50];
	char MovieTheaterMap[50];
	struct BSTnode *left;
	struct BSTnode *right;
};

struct BSTnode *CreateBST(struct BSTnode **, char [], char [], char []);
struct BSTnode *SearchForMovieTheater(struct BSTnode *, char []);
void ListZipsInOrder(struct BSTnode *);
void WriteOutNode(struct BSTnode *, FILE *);
#endif
