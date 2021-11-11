//Matthew Irvine 1001401200
// * in a comment like this means that I need to go back an check/redo a part I am unsure about.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListLib.h"

#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct{
	int SeatNumber;
	char SeatRow;
	int sold;
} Seat;

void ReadMovieTheater(Seat MovieTheater[][MAX_COLS], char InputFilename[])
{
	FILE *MyFile = fopen(InputFilename, "r");
	if(MyFile == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	
	char Buffer[500];
	fgets(Buffer, 500, MyFile);
	close();
	
	int x;
	int counter=0;
	for(x=0; x<MAX_ROWS; x++)
	{
		int y;
		for(y=0; y<MAX_COLS;y++)
		{
			MovieTheater[x][y].sold= Buffer[counter]-48;
			counter++;
		}
	}
}

void WriteMovieTheater(Seat MovieTheater[][MAX_COLS], char OutputFilename[])
{
	FILE *MyFile= fopen(OutputFilename, "w");
	if(MyFile == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	
	int x;
	for(x=0; x<MAX_ROWS; x++)
	{
		int y;
		for(y=0; y<MAX_COLS;y++)
		{
			fprintf(MyFile, "%d", MovieTheater[x][y].sold);
		}
	}
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
	struct node *LinkedListHead = NULL;
	
	Seat MovieTheater[MAX_ROWS][MAX_COLS]= {};
	char InputFilename[30];
	char OutputFilename[30];
	get_command_line_parameter(argv,"INPUTFILENAME=",InputFilename);		// *
	get_command_line_parameter(argv,"OUTPUTFILENAME=", OutputFilename);		// *
	
	ReadMovieTheater(MovieTheater, InputFilename);
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
		
		int ArrayRow= (int) Row -65;
		
		while((ArrayRow< 0 || ArrayRow>MAX_ROWS )|| (SeatNumber<=0 || SeatNumber>MAX_COLS))
		{
			printf("Choice invalid\nPlease Reenter Row and Seat number: \n");
			scanf("%c%d", &Row, &SeatNumber);
			getchar();
			Row = toupper(Row);
		}
		
		int ArrayCol=SeatNumber-1;			
		
		if(SeatAvailable(&MovieTheater[ArrayRow][ArrayCol])!=1)
		{
			SellSeat(&MovieTheater[ArrayRow][ArrayCol]);
			AddSoldSeatToList(&LinkedListHead, Row, SeatNumber);	
		}
		else
		{
			printf("This seat is not available.\n");
			x =0; 
		}
		PrintSeatMap(MovieTheater);
	}
	
	PrintTickets(LinkedListHead);	
	WriteMovieTheater(MovieTheater, OutputFilename);
	getchar(); 
	return 0;
}
