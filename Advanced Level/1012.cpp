#include <iostream>
#include <algorithm>
using namespace std;

int exist[1000000], round = 0;

struct student
{
	int id;
	int best;
	int grade[4]; // 'A'、'C'、'M'、'E'
	int rank[4];
} stu[2005];

bool cmp(student s1, student s2)
{
	return s1.grade[round] > s2.grade[round];
}
int main()
{
	int n, m, id;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3 + 0.5;
	}

	for (round = 0; round < 4; round++)
	{
		sort(stu, stu + n, cmp);
		stu[0].rank[round] = 1;
		for (int i = 1; i < n; i++)
		{
			stu[i].rank[round] = i + 1;
			if (stu[i].grade[round] == stu[i - 1].grade[round])
				stu[i].rank[round] = stu[i - 1].rank[round];
		}
	}

	for (int i = 0; i < n; i++)
	{
		exist[stu[i].id] = i + 1; // 记录存在的学生
		stu[i].best = 0;
		int minrank = stu[i].rank[0];
		for (int j = 1; j <= 3; j++)
		{
			if (stu[i].rank[j] < minrank)
			{
				minrank = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}

	char c[4] = {'A', 'C', 'M', 'E'};
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		if (exist[id] > 0) //存在该学生
		{
			int temp = exist[id] - 1;
			int best = stu[temp].best;
			cout << stu[temp].rank[best] << " " << c[best] << endl;
		}
		else
			cout << "N/A" << endl;
	}
	return 0;
}