#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, x, y;
	string id, maxId, minId;
	double dist, maxdist = 0, mindist = 200;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> x >> y;
		dist = sqrt(pow(x, 2) + pow(y, 2));
		if (dist > maxdist)
		{
			maxdist = dist;
			maxId = id;
		}
		if (dist < mindist)
		{
			mindist = dist;
			minId = id;
		}
	}
	cout << minId << " " << maxId << endl;
	return 0;
}