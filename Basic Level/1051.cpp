#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double r1, r2, p1, p2;
	scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
	double a1 = r1 * cos(p1);
	double b1 = r1 * sin(p1);
	double a2 = r2 * cos(p2);
	double b2 = r2 * sin(p2);

	double a = a1 * a2 - b1 * b2;
	double b = a1 * b2 + a2 * b1;
	if (a < 0 && a > -0.005)
		printf("0.00");
	else
		printf("%.02lf", a);

	if (b < 0 && b > -0.005)
		printf("+0.00i");
	else if (b >= 0)
		printf("+%.02lfi", b);
	else
		printf("%.02lfi", b);
}