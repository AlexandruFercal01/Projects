#include "CommandTaker.h"

CommandTaker::CommandTaker() {};

//verifica carousel si daca exista elementul cautat in carousel il ia de acolo, altfel preda
//comanda la cakeMaker
Cake CommandTaker::takeCommand(RecipeCake recipe)
{
	int i=0, ok=0;
	vector<Cake>::iterator it;
	for (it = carousel.storage.begin(); it != carousel.storage.end(); it++, i++)
	{
		if (carousel.storage[i].getName() == recipe.getName())
		{
			ok++;
		}
	}
	if (ok == 0)
	{
		cout << "Comanda dumneavoastra este indisponibila in carusel. Vom trimite de stire cofetarului!" << endl;
		Sleep(5000);
		cout << "Comanda este gata: ";
		cout << recipe.getName() << endl;
		return cakeMaker.takeCommand(recipe);
	}
	else
	{
		cout << "Comanda este gata: ";
		cout << recipe.getName() << endl;
		return carousel.getCake(recipe.getName());
	}
}

//preia direct de la CakeMaker
//HighBloodGlucose = nr torturi
vector<Cake> CommandTaker::takeCommand(RecipeCake recipe, int HighBloodGlucose)
{
	cout << "Comanda necesita mai mult timp pentru preparare. Va rugam asteptati!" << endl;
	Sleep(HighBloodGlucose * 5000);
	vector<Cake> CakeVector;
	for (int i = 0; i < HighBloodGlucose; i++)
	{
		 CakeVector.push_back(cakeMaker.takeCommand(recipe));
	}
	for (int j = 0; j < HighBloodGlucose; j++)
	{
		cout << CakeVector[j].getName()<< endl;
	}
	return CakeVector;
}

Cake CommandTaker::takeCommand(string NameOfCake)
{
	return carousel.getCake(NameOfCake);
}

vector<Cake> CommandTaker::getCakesFromCarousel()
{
	if (carousel.storage.size() <= 3)
	{
		CommandTaker::refillCarousel();
	}
	return carousel.storage;
}

bool CommandTaker::checkCarouselOfCakes()
{
	cout << carousel.getCurrentCapacity();
	return true;
}

bool CommandTaker::refillCarousel()
{
	Cake Cake1("Savarina");
	Cake Cake2("Ecler");
	Cake Cake3("Placinta");
	Cake Cake4("Tiramisu");
	Cake Cake5("Cheesecake");
		carousel.addCake(Cake1);
		carousel.addCake(Cake2);
		carousel.addCake(Cake3);
		carousel.addCake(Cake4);
		carousel.addCake(Cake5);
		carousel.addCake(Cake1);
		carousel.addCake(Cake2); 
	return true;
};



