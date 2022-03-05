#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void anbisect(int *nrzile, int an)
{
	if (an % 4 != 0)
		*nrzile += 28;
	else
		if (an % 100 != 0)
			*nrzile += 29;
		else
			if (an % 400 != 0)
				*nrzile += 28;
			else
				*nrzile += 29;
}
int main()
{ 
	char data1[256], data2[256];
	int ziua1, an1, ziua2, an2; char luna1[256], luna2[256];
	int nrzile1 = 0, nrzile2 = 0, an, nrduminici1, nrduminici2, nrduminici;
	printf("Introduceti prima data: ");
	gets(data1, 256, stdin);
	printf("Introduceti a doua data: ");
	gets(data2, 256, stdin);
	char *p = strtok(data1, " /");
	if (p) ziua1 = atoi(p);
	p = strtok(NULL, " /");
	if (p)strcpy(luna1, p);
	p = strtok(NULL, " /");
	if (p) an1 = atoi(p);
	//atoi-converteste un string in int
	p = strtok(data2, " /");
	if (p) ziua2 = atoi(p);
	p = strtok(NULL, " /");
	if (p)strcpy(luna2, p);
	p = strtok(NULL, " /");
	if (p) an2 = atoi(p);
	if (islower(luna1[0]))
		luna1[0] = toupper(luna1[0]);
	if (islower(luna2[0]))
		luna2[0] = toupper(luna2[0]);
	//determin nr de zile pana la data1 incepand de la 1 Ianuarie 1900
	for (an = 1900; an < an1; an++)
	{ //verific daca anul este bisect
		if (an % 4 != 0)
			nrzile1 += 365;
		else
			if (an % 100 != 0)
				nrzile1 += 366;
			else
				if (an % 400 != 0)
					nrzile1 += 365;
				else
					nrzile1 += 366;

	}
	for (an = 1900; an < an2; an++)
	{ ///verific daca anul este bisect
		if (an % 4 != 0)
			nrzile2 += 365;
		else
			if (an % 100 != 0)
				nrzile2 += 366;
			else
				if (an % 400 != 0)
					nrzile2 += 365;
				else
					nrzile2 += 366;

	}

	//verific anul din data1
	if (strcmp(luna1, "Ianuarie") == 0)   nrzile1 += ziua1;
	if (strcmp(luna2, "Ianuarie") == 0)   nrzile2 += ziua2;
	if (strcmp(luna1, "Februarie") == 0) { nrzile1 += 31; nrzile1 += ziua1; }
	if (strcmp(luna2, "Februarie") == 0) { nrzile2 += 31; nrzile2 += ziua2; }
	if (strcmp(luna1, "Martie") == 0) {
		nrzile1 += 31;
		anbisect(&nrzile1, an1);  nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Martie") == 0) {
		nrzile2 += 31;
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Aprilie") == 0) {
		nrzile1 += (31 * 2);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Aprilie") == 0) {
		nrzile2 += (31 * 2);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}

	if (strcmp(luna1, "Mai") == 0) {
		nrzile1 += (31 * 2); nrzile1 += 30;
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Mai") == 0) {
		nrzile2 += (31 * 2); nrzile2 += 30;
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Iunie") == 0) {
		nrzile1 += (31 * 3); nrzile1 += 30;
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Iunie") == 0) {
		nrzile2 += (31 * 3); nrzile2 += 30;
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Iulie") == 0) {
		nrzile1 += (31 * 3); nrzile1 += (30 * 2);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Iulie") == 0) {
		nrzile2 += (31 * 3); nrzile2 += (30 * 2);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "August") == 0) {
		nrzile1 += (31 * 4); nrzile1 += (30 * 2);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "August") == 0) {
		nrzile2 += (31 * 4); nrzile2 += (30 * 2);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}

	if (strcmp(luna1, "Septembrie") == 0) {
		nrzile1 += (31 * 5); nrzile1 += (30 * 2);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Septembrie") == 0) {
		nrzile2 += (31 * 5); nrzile2 += (30 * 2);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Octombrie") == 0) {
		nrzile1 += (31 * 5); nrzile1 += (30 * 3);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Octombrie") == 0) {
		nrzile2 += (31 * 5); nrzile2 += (30 * 3);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Noiembrie") == 0) {
		nrzile1 += (31 * 6); nrzile1 += (30 * 3);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Noiembrie") == 0) {
		nrzile2 += (31 * 6); nrzile2 += (30 * 3);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	if (strcmp(luna1, "Decembrie") == 0) {
		nrzile1 += (31 * 6); nrzile1 += (30 * 4);
		anbisect(&nrzile1, an1); nrzile1 += ziua1;

	}
	if (strcmp(luna2, "Decembrie") == 0) {
		nrzile2 += (31 * 6); nrzile2 += (30 * 4);
		anbisect(&nrzile2, an2); nrzile2 += ziua2;

	}
	nrduminici1 = nrzile1 / 7;
	nrduminici2 = nrzile2 / 7;
	nrduminici = nrduminici2 - nrduminici1;
	printf("%d duminici ", nrduminici);
	system("pause");
	return 0;
}
