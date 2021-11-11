// Matthew Irvine 1001401200
#include "MyLib.h"
#include <limits.h>
void ConvertDecimalToBinary(int deci){
	int Array[8] = {0,0,0,0,0,0,0,0};
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
	
	int i;
	for(i = 7; i >=0 ; i--)
	{
		printf("%d", Array[i]);
	}
	printf("\n");
}
