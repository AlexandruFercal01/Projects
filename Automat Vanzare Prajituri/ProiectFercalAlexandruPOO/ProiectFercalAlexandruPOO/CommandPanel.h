#pragma once
#include "CommandTaker.h"
#include <list>


class CommandPanel
{
private:
	list<RecipeCake> menu;
	CommandTaker commandTaker;
public:
	CommandPanel();
	void showProducts();
	void selectProduct(string);
	void selectProduct(string, int);
	void showProductsInCarousel();
	
};

