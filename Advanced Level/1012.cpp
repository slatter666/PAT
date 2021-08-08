#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int id;
	int best;
	int score[4];
	int rank[4];
} stu[2005];

int flag;
int exist[1000000] = {0};
bool cmp(node s1, node s2)
{
	return s1.score[flag] > s2.score[flag];
}

int main()
{
	int n, m, search;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
	}

	for (flag = 0; flag <= 3; flag++)
	{
		sort(stu, stu + n, cmp);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; i++)
		{
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag])
				stu[i].rank[flag] = stu[i - 1].rank[flag];
		}
	}

	for (int i = 0; i < n; i++)
	{
		exist[stu[i].id] = i + 1;
		int temp = stu[i].rank[0];
		stu[i].best = 0;
		for (int j = 1; j <= 3; j++)
		{
			if (stu[i].rank[j] < temp)
			{
				temp = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}

	char c[4] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < m; i++)
	{
		cin >> search;
		int temp = exist[search];
		if (temp)
		{
			int best = stu[temp - 1].best;
			cout << stu[temp - 1].rank[best] << " " << c[best] << endl;
		}
		else
			cout << "N/A" << endl;
	}
	return 0;
}