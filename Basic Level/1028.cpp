#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct people
{
	char name[10];
	int year;
	int month;
	int day;
};

bool check(people peo)
{
	if ((peo.year > 2014) || (peo.year == 2014 && peo.month > 9) || (peo.year == 2014 && peo.month == 9 && peo.day > 6))
	{
		return false;
	}
	else if ((peo.year < 1814) || (peo.year == 1814 && peo.month < 9) || (peo.year == 1814 && peo.month == 9 && peo.day < 6))
	{
		return false;
	}
	return true;
}

bool checkyoung(people young, people peo)
{
	if ((peo.year > young.year) || (peo.year == young.year && peo.month > young.month) || (peo.year == young.year && peo.month == young.month && peo.day > young.day))
	{
		return true;
	}
	return false;
}

bool checkold(people old, people peo)
{
	if ((peo.year < old.year) || (peo.year == old.year && peo.month < old.month) || (peo.year == old.year && peo.month == old.month && peo.day < old.day))
	{
		return true;
	}
	return false;
}

int main()
{
	int n, count = 0;
	people temp, youngest = {"youngest", 1814, 9, 5}, oldest = {"oldest", 2014, 9, 7};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", &temp.name, &temp.year, &temp.month, &temp.day);
		if (check(temp))
		{
			count++;
			if (checkyoung(youngest, temp))
				youngest = temp;
			if (checkold(oldest, temp))
				oldest = temp;
		}
	}

	printf("%d", count);
	if (count != 0)
		printf(" %s %s\n", oldest.name, youngest.name);
	return 0;
}