//Matthew Irvine 1001401200
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BSTLib.h"
#include "QueueLib.h"
#include "StackLib.h"

#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct{
	int SeatNumber;
	char SeatRow;
	int sold;
} Seat;

void ReadMovieTheater(Seat MovieTheater[][MAX_COLS], char InputFilename[], struct BSTnode **root, struct BSTnode **SelectedMovieTheater)
{
	FILE *MyFile = fopen(InputFilename, "r");
	if(MyFile == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	
	char s[] = "|";
	char Buffer[500];
	char text1[50];
	char text2[6];
	char text3[50];
	while(fgets(Buffer, sizeof(Buffer)-1, MyFile))
	{
		fgets(Buffer, 500, MyFile);
		strcpy(text1, strtok(Buffer, s));
		strcpy(text2, strtok(NULL, s));
		strcpy(text3, strtok(NULL, s));
		*root = CreateBST(root, text1, text2, text3);
	}
	
	char tmpZip[6];
	do
	{
		ListZipsInOrder(*root);
		printf("Which Zip Code do you want to watch the Movie at?\n");
		scanf("%s", &tmpZip);
		getchar();
		
		//printf("%p, %s", *SelectedMovieTheater, (*SelectedMovieTheater)->MovieTheaterZip);
		*SelectedMovieTheater = SearchForMovieTheater(*root, tmpZip); //*
		if(*SelectedMovieTheater == NULL)
			printf("Zip Code not Available\n"); //*
	}
	while(*SelectedMovieTheater == NULL);
	
	int x;
	int counter=0;
	char Buf[500];
	for(x=0; x<MAX_ROWS; x++)
	{
		int y;
		for(y=0; y<MAX_COLS;y++)
		{
			strcpy(Buf, (**SelectedMovieTheater).MovieTheaterMap);
			MovieTheater[x][y].sold= Buf[counter]-48;
			counter++;
		}
	}
	
	close();
}

void WriteMovieTheater(Seat MovieTheater[][MAX_COLS], char OutputFilename[], struct BSTnode *root, struct BSTnode *SelectedMovieTheater)
{
	FILE *MyFile= fopen(OutputFilename, "w");
	if(MyFile == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	
	int x;
	int counter =0;
	char Buf[25];
	for(x=0; x<MAX_ROWS; x++)
	{
		int y;
		for(y=0; y<MAX_COLS;y++)
		{
			Buf[counter] = MovieTheater[x][y].sold;
			//printf("%c", (char) MovieTheater[x][y].sold+48);
			printf("%c", Buf);
		}
	}
	strcpy(SelectedMovieTheater->MovieTheaterMap,Buf);
	printf("%s", Buf);
	WriteOutNode(root, MyFile);
	close();
}

int SeatAvailable(Seat *MovieSeatptr)
{
	return MovieSeatptr->sold;
}

void SellSeat(Seat *MovieSeatptr)
{
	MovieSeatptr->sold= 1;
	return;
}

void PrintSeatMap(Seat MovieTheater[][MAX_COLS])
{
	int counter =0;
	int x;
	for( x=0; x<=MAX_ROWS; x++)
	{
		int y;
		for(y=0; y<=MAX_COLS; y++)
		{		
			if(x==0 && y==0)
					printf("\t");

			else
			{
				if(x==0)
					printf("Seat %d\t", y);
				else if(y==0)
					printf("Row %c\t", x+64);
				else if(MovieTheater[x-1][y-1].sold == 1)
					printf("X\t");
				else
					printf("O\t");
				
				if(y==MAX_COLS)
					printf("\n");
			}
			
		}
		counter =0;
	}
	printf("\n");
}

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i  = 0; 
	
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
	
	return;
}

int main(int argc, char *argv[])
{
	struct qnode *QueueHead= NULL;
	struct qnode *QueueTail= NULL;
	struct snode *StackTop= NULL;
	struct BSTnode *root= NULL;
	struct BSTnode *SelectedMovieTheater = NULL;
	
	Seat MovieTheater[MAX_ROWS][MAX_COLS]= {};
	char InputFilename[30];
	char OutputFilename[30];
	char PrintType[30];
	get_command_line_parameter(argv,"INPUTFILENAME=",InputFilename);		
	get_command_line_parameter(argv,"OUTPUTFILENAME=", OutputFilename);	
	get_command_line_parameter(argv,"PRINTTYPE=", PrintType);	
	
	ReadMovieTheater(MovieTheater, InputFilename, &root, &SelectedMovieTheater);
	PrintSeatMap(MovieTheater);
	
	int NumberOfTickets;
	printf("How many tickets would you like to buy?\n");
	scanf("%d", &NumberOfTickets);
	getchar();
	
	int x;
	for(x= 0; x<NumberOfTickets; x++)
	{
		printf("What Row and Seat number would you like?\n");
		char Row;
		int SeatNumber;
		scanf("%c%d", &Row, &SeatNumber);
		getchar();
		Row = toupper(Row);
		int ArrayRow= (int) Row -65;
		
		while((ArrayRow< 0 || ArrayRow>MAX_ROWS )|| (SeatNumber<0 || SeatNumber>MAX_COLS))
		{
			printf("Choice invalid\nPlease Reenter Row and Seat number: \n");
			scanf("%c%d", &Row, &SeatNumber);
			getchar();
			Row = toupper(Row);
			int ArrayRow= (int) Row -65;
		}
		
		int ArrayCol=SeatNumber-1;			
		
		if(SeatAvailable(&MovieTheater[ArrayRow][ArrayCol])!=1)
		{
			SellSeat(&MovieTheater[ArrayRow][ArrayCol]);
			if(strcmp(PrintType, "QUEUE") == 0)
				EnqueueSoldSeat(&QueueHead, &QueueTail, Row, SeatNumber);
			else
				PushSoldSeat(&StackTop, Row, SeatNumber);
		}
		else
		{
			printf("This seat is not available.\n");
			x =0; 
		}
		PrintSeatMap(MovieTheater);
	}
	if(strcmp(PrintType, "QUEUE") == 0)
		DequeueTickets(QueueHead);
	else
		PopTickets(StackTop);	
	WriteMovieTheater(MovieTheater, OutputFilename, root, SelectedMovieTheater);
	getchar(); 
	return 0;
}
