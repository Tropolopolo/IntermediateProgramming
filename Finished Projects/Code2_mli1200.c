//Matthew L Irvine 1001401200
#include <stdio.h>

void ConvertDecimalToBinary(int deci, int Array[])
{
	int x;
	for(x = 0; deci > 0; x++)
	{
		if(deci&1)
		{
			Array[x]= 1;
		}
		else
		{
			Array[x]= 0;
		}
		deci =deci>>1;
	}
}

void PrintBinary(int Array[])
{
	int i;
	for(i = 7; i >=0 ; i--)
	{
		printf("%d", Array[i]);
	}
	printf("\n");
}

int main(void)
{
	int Base10 = 0;
	int BinaryArray[8];
	
	printf("Type a decimal number between 0 and 255: ");
	scanf("%d", &Base10);
	
	while(Base10>255 || Base10<0)
	{
		printf("Please type a decimal number between 0 and 255: ");
		scanf("%d", &Base10);
	}
	
	ConvertDecimalToBinary(Base10, BinaryArray);
	printf("Decimal %d converts to binary ", Base10);
	PrintBinary(BinaryArray);
}
