#include <iostream>
using namespace std;

int main()
{
	int c1, c2;
	cin >> c1 >> c2;
	int time = (c2 - c1 + 50) / 100;
	int hour = time / 3600;
	time %= 3600;
	int min = time / 60;
	int sec = time % 60;
	printf("%02d:%02d:%02d", hour, min, sec);
	return 0;
}