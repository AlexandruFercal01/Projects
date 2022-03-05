#pragma once
#include "Cake.h"
#include <vector>

class CarouselOfCakes
{
private:
	
	unsigned int maxCapacity = 10;
	unsigned int lowLimit = 3;
public:
	vector<Cake> storage;
	CarouselOfCakes();
	bool addCake(Cake);
	Cake getCake(string);
	int getCurrentCapacity();
};

