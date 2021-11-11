//Matthew Irvine 1001401200

#ifndef _SockLib_H
#define _SockLib_H
typedef struct 
	{
		int DrawerID;
		int NumberOfSocks;
		char SockColor[10];
		int MaxDrawerCapacity;
	}SockDrawer;
	int DrawerIDCompare(const void *, const void *);
	int NumberOfSocksCompare(const void *, const void *);
	int MaxCapacityCompare(const void *, const void *);
	int SockColorCompare(const void *, const void *);
#endif
