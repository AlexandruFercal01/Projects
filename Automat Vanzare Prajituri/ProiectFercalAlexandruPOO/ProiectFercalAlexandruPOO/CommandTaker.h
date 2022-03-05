#pragma once
#include "CakeMaker.h"
#include "CarouselOfCakes.h"
#include <Windows.h>


class CommandTaker
{
private:
	CakeMaker cakeMaker;
	RecipeCake carouselRecipe;
	CarouselOfCakes carousel;
	bool checkCarouselOfCakes();
	bool refillCarousel();
public:
	CommandTaker();
	Cake takeCommand(RecipeCake);
	vector<Cake> takeCommand(RecipeCake, int);
	Cake takeCommand(string);
	vector<Cake> getCakesFromCarousel();
	
};

