#pragma once
#include <iostream>
#include <string>

using namespace std;

class RecipeCake
{
private:
	string name;
	int time;
public:
	RecipeCake();
	RecipeCake(string, int);
	string getName();
	int getTime();

};

