#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int pg, ps, pk;
	int ag, as, ak;

	scanf("%d.%d.%d", &pg, &ps, &pk);
	scanf("%d.%d.%d", &ag, &as, &ak);

	int p = pg * 17 * 29 + ps * 29 + pk;
	int a = ag * 17 * 29 + as * 29 + ak;

	int diff = a - p;
	if (diff < 0)
	{
		cout << "-";
		diff = -diff;
	}

	int gallenon = diff / (17 * 29);
	diff %= 17 * 29;
	int sickle = diff / 29;
	int knut = diff % 29;
	cout << gallenon << "." << sickle << "." << knut;
	return 0;
}