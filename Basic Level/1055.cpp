#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	int height;
} stu[10005];

bool cmp(student a, student b)
{
	return a.height != b.height ? a.height < b.height : a.name > b.name;
}

int main()
{
	int n, k, m, last;
	cin >> n >> k;
	m = n / k;
	last = n % k + m;
	student s[k][last];
	for (int i = 0; i < n; i++)
		cin >> stu[i].name >> stu[i].height;

	sort(stu, stu + n, cmp);

	for (int i = 0; i < k; i++)
	{
		int rec = i == k - 1 ? last : m;
		int top, left, right;
		top = i * m + rec - 1;
		if (i != k - 1)
			left = right = m / 2;
		else
			left = right = last / 2;

		for (int j = 0; j < rec; j++)
		{
			if (j == 0)
			{
				s[i][left] = stu[top--];
				left--;
				right++;
			}
			else if (j % 2 == 1)
				s[i][left--] = stu[top--];
			else
				s[i][right++] = stu[top--];
		}
	}

	for (int i = k - 1; i >= 0; i--)
	{
		int rec = i == k - 1 ? last : m;
		for (int j = 0; j < rec; j++)
		{
			cout << s[i][j].name;
			if (j != rec - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}