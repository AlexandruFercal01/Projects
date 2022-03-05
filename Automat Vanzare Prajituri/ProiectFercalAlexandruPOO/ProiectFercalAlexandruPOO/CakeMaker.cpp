#include "CakeMaker.h"

CakeMaker::CakeMaker() {}

Cake CakeMaker::takeCommand(RecipeCake recipe)
{
	Cake c(recipe.getName());
	return c;
}
