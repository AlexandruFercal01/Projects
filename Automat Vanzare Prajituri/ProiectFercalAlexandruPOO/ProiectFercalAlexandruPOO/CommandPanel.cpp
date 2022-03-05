#include "CommandPanel.h"

CommandPanel::CommandPanel()
{
	RecipeCake recipe1("Savarina", 60);
	RecipeCake recipe2("Ecler", 45);
	RecipeCake recipe3("Placinta", 90);
	RecipeCake recipe4("Tiramisu", 60);
	RecipeCake recipe5("Cheesecake", 60);
	menu.push_back(recipe1);
	menu.push_back(recipe2);
	menu.push_back(recipe3);
	menu.push_back(recipe4);
	menu.push_back(recipe5);
}

void CommandPanel::showProducts()
{
	list<RecipeCake>::iterator it;
	cout << "Meniul cu prajituri:" << endl;
	cout << "-------------------" << endl;
	for  (it = menu.begin(); it != menu.end(); it++)
	{
		RecipeCake rp1 = *it;
		cout << rp1.getName() << endl;
		cout << "-------------" << endl;
	}
}

void CommandPanel::selectProduct(string name)
{
	RecipeCake recipe(name, 0);
	commandTaker.takeCommand(recipe);
}

void CommandPanel::selectProduct(string name, int numberOfProducts)
{
	RecipeCake recipe(name, 0);
	commandTaker.takeCommand(recipe, numberOfProducts);
}

void CommandPanel::showProductsInCarousel()
{
	vector<Cake> cake= commandTaker.getCakesFromCarousel();
	vector<Cake>::iterator it;
	for (it = cake.begin(); it != cake.end(); it++)
	{
		Cake c = *it;
		cout << c.getName() << endl;
	}
	
}




