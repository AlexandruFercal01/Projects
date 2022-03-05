#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <conio.h>
#include "CommandPanel.h"
#pragma warning(disable:4996)
using namespace std;

int main()
{
	CommandPanel commandPanel;
	int opt;
	do
	{
		system("CLS");
		cout << "1. Afisati meniul cu prajituri." << endl;
		cout << "2. Afisati prajiturile existente in carusel." << endl;
		cout << "3. Comandati o prajitura." << endl;
		cout << "0. Iesire." << endl;
		cout << "Tastati optiunea dorita:";
		cin >> opt;
		switch (opt)
		{
		case 0:
			cout << " Multumim pentru vizita!" << endl;
			exit(0);
			break;
		case 1:
			cout << endl;
			commandPanel.showProducts();
			cout << endl << "Apasati orice tasta pentru a continua." << endl;
			getch();
			break;
		case 2:
			cout << endl;
			commandPanel.showProductsInCarousel();
			cout << endl << "Apasati orice tasta pentru a continua." << endl;
			getch();
			break;
		case 3:
			int decision;
			string cakeName;
			int cakeQuantity;
			cout << endl;
			cout << "Doriti sa cumparati mai multe bucati? (1-da/0-nu)" << endl;
			cin >> decision;
			if (decision == 1)
			{
				cout << "Introduceti numele prajiturii pe care o cautati:";
				cin >> cakeName;
				cout << "Cate bucati doriti?" << endl;
				cin >> cakeQuantity;
				commandPanel.selectProduct(cakeName, cakeQuantity);
				cout << endl << "Apasati orice tasta pentru a continua." << endl;
				getch();
			}
			else if (decision == 0)
			{
				cout << "Introduceti numele prajiturii pe care o cautati:";
				getline(cin>>ws, cakeName);
				commandPanel.selectProduct(cakeName);
				cout << endl << "Apasati orice tasta pentru a continua." << endl;
				getch();
			}
			break;
		}

	} while (1);
	return 0;
}
