#include <iostream>
using namespace std;

int grade[100005] = {0};

int main()
{
	int n, max_id = 0;
	cin >> n;
	while (n--)
	{
		int id, point;
		cin >> id >> point;
		grade[id] += point;
		if (id > max_id)
			max_id = id;
	}

	int max_point = 0, index;
	for (int i = 1; i <= max_id; i++)
	{
		if (grade[i] > max_point)
		{
			index = i;
			max_point = grade[i];
		}
	}
	cout << index << " " << max_point << endl;
}