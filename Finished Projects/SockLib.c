//Matthew Irvine 1001401200
#include "SockLib.h"
int DrawerIDCompare(const void *a, const void *b)
{
	return (((SockDrawer*)a)->DrawerID -((SockDrawer*)b)->DrawerID);
}

int NumberOfSocksCompare(const void *a, const void *b)
{
	return (((SockDrawer*)a)->NumberOfSocks -((SockDrawer*)b)->NumberOfSocks);
}

int MaxCapacityCompare(const void *a, const void *b)
{
	return (((SockDrawer*)a)->MaxDrawerCapacity -((SockDrawer*)b)->MaxDrawerCapacity);
}

int SockColorCompare(const void *a, const void *b)
{
	return (((SockDrawer*)a)->SockColor -((SockDrawer*)b)->SockColor);
}
