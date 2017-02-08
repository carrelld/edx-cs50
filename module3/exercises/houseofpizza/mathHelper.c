#include "mathHelper.h"
#include <math.h>

// TODO: cut the function from houseOfPizza.c and put it here, so we can use it in houseOfTires.c

int numberOfContainers(int numberOfUnits, int unitsPerContainer)
{
	// calculate number of containers to order using ceil from math.h
	float numberToOrder = ceil(((float)numberOfUnits)/unitsPerContainer);
	return (int)numberToOrder;
}