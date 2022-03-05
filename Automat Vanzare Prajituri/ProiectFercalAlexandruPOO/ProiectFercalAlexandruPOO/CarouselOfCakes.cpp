#include "CarouselOfCakes.h"

CarouselOfCakes::CarouselOfCakes() 
{
	Cake Cake1("Savarina");
	Cake Cake2("Ecler");
	Cake Cake3("Placinta");
	Cake Cake4("Tiramisu");
	Cake Cake5("Cheesecake");
	storage.push_back(Cake1);
	storage.push_back(Cake2);
	storage.push_back(Cake3);
	storage.push_back(Cake4);
	storage.push_back(Cake5);
	storage.push_back(Cake1);
	storage.push_back(Cake2);
	storage.push_back(Cake3);
	storage.push_back(Cake4);
	storage.push_back(Cake5);
};

bool CarouselOfCakes::addCake(Cake cake)
{
	storage.push_back(cake);
	return true;
};

Cake CarouselOfCakes::getCake(string name)
{
	Cake aux;
	vector<Cake>::iterator it;
	int i = 0, ok=0;
	for ( it = storage.begin(); it != storage.end(); ++it, ++i)
	{
		if (storage[i].getName() == name)
		{
			aux = storage[i];
			storage.erase(it);
			return aux;
		}	
	}
}

int CarouselOfCakes::getCurrentCapacity()
{
	cout << storage.size()<< endl;
	return storage.size();
}
