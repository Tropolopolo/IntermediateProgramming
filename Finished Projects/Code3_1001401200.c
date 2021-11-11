//Matthew Irvine 1001401200
#include <stdio.h>

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
