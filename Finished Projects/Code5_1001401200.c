// Matthew Irvine 1001401200

#include <string.h>
#include <stdio.h>
int NumDrawers;

struct SockDrawer
	{
		int DrawerID;
		int NumberOfSocks;
		char SockColor[10];
		int MaxDrawerCapacity;
	};
	
void DisplayMyDresser(struct SockDrawer Dresser[])
{
	int x;
	
	for(x =0; x<NumDrawers; x++)
	{
		printf("DrawerID: %d, Number of socks: %d, Color: %s, Max Capacity: %d\n", Dresser[x].DrawerID, Dresser[x].NumberOfSocks, Dresser[x].SockColor, Dresser[x].MaxDrawerCapacity);	
	}
}

void PutAwayMySocks(struct SockDrawer Dresser[])
{
	int DrawerID;
	int HowMany;
	
	printf("What is the DrawerID: ");
	scanf("%d", &DrawerID);
	getchar();
	DrawerID= DrawerID--;
	
	if(DrawerID<0 || DrawerID>NumDrawers)
	{
		printf("That's not one of your drawers!\n");
		return;
	}
	printf("How Many Socks Are There: ");
	scanf("%d", &HowMany);
	getchar();
	
	if(HowMany > Dresser[DrawerID].MaxDrawerCapacity)
	{
		HowMany = HowMany - Dresser[DrawerID].MaxDrawerCapacity;
		printf("%d socks fit in the drawer, %d fell on the floor", Dresser[DrawerID].MaxDrawerCapacity, HowMany);
		Dresser[DrawerID].NumberOfSocks = Dresser[DrawerID].MaxDrawerCapacity;
	}
	else
		Dresser[DrawerID].NumberOfSocks = HowMany;
}

void PutOnMySocks(struct SockDrawer Dresser[])
{
	int DrawerID;
	int HowMany;
	
	printf("What is the DrawerID: ");
	scanf("%d", &DrawerID);
	getchar();
	DrawerID= DrawerID--;
	
	if(DrawerID<0 || DrawerID>NumDrawers)
	{
		printf("That's not one of your drawers!!\n");
		return;
	}
	printf("How Many Socks Need to Be Taken: ");
	scanf("%d", &HowMany);
	getchar();
	
	if(Dresser[DrawerID].NumberOfSocks < HowMany)
	{
		printf("I do not have %d socks, I can get %d socks\n", HowMany, Dresser[DrawerID].NumberOfSocks);
		Dresser[DrawerID].NumberOfSocks = 0;
	}
	else
		Dresser[DrawerID].NumberOfSocks= Dresser[DrawerID].NumberOfSocks - HowMany;	
}

void CreateDresser(struct SockDrawer *MyDresser, int DrawerID)
{
	int HowMany;
	MyDresser->DrawerID = ++DrawerID;
	
	printf("How many socks can fit in Drawer %d: ", MyDresser->DrawerID);
	scanf("%d", &MyDresser->MaxDrawerCapacity);
	getchar();
	printf("how many socks are you putting in Drawer %d: ", MyDresser->DrawerID);
	scanf("%d", &HowMany);
	getchar();
	
	if(HowMany> MyDresser->MaxDrawerCapacity)
	{
		HowMany= HowMany - MyDresser->MaxDrawerCapacity;
		printf("%d socks can fit into the Drawer, %d fell on the floor\n", MyDresser->MaxDrawerCapacity, HowMany);
		MyDresser->NumberOfSocks = MyDresser->MaxDrawerCapacity;
	}
	else
	{
		MyDresser->NumberOfSocks= HowMany;
	}
	printf("What is the color of the socks: ");
	fgets(MyDresser->SockColor, sizeof(MyDresser->SockColor)-1, stdin);
	MyDresser->SockColor[strlen(MyDresser->SockColor) - 1] = '\0';
}

int main()
{
	struct SockDrawer Dresser[10];
		
	enum SockAction
	{
		RemoveSocks=1, AddSocks, DisplayDresser
	}Action;

	int Choice; 
	
	int counter=0;
	do{
		if(counter == 0)
		{
			printf("How Many Drawers does the dresser have (1-10): ");
			scanf("%d", &NumDrawers);
			getchar();
			if(NumDrawers == 0)
			{
				return 0;
			}
			counter++;
		}
		else{
			printf("Please Reenter How Many Drawers does the dresser has (1-10): ");
			scanf("%d", &NumDrawers);
			getchar();
		}
	}while(!(NumDrawers>1 && NumDrawers<10));
		
	int x;
	for(x= 0; x< NumDrawers; x++)
	{
		CreateDresser(&Dresser[x],x);
	}
	
	do{
		printf("Choose an option:\n 0- exit \n 1- remove socks \n 2- add socks \n 3- display dresser \n");
		scanf("%d", &Choice);
		getchar();
		
		switch(Choice)
		{
			case RemoveSocks:
				PutOnMySocks(Dresser);
				DisplayMyDresser(Dresser);
				break;
			case AddSocks:
				PutAwayMySocks(Dresser);
				DisplayMyDresser(Dresser);
				break;
			case DisplayDresser:
				DisplayMyDresser(Dresser);
				break;
			default:
				Choice =0;
		}
	}while(Choice != 0);

	return 0;
}
