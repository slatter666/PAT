#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	int id;
	int de;
	int cai;
	int sum;
};

bool cmp(student s1, student s2)
{
	if (s1.sum != s2.sum)
	{
		return s1.sum > s2.sum;
	}
	else if (s1.de != s2.de)
	{
		return s1.de > s2.de;
	}
	else
	{
		return s1.id < s2.id;
	}
}

int main()
{
	int n, l, h;
	vector<student> v1, v2, v3, v4; //第一类、第二类、第三类、第四类考生
	cin >> n >> l >> h;
	student stu;
	while (n--)
	{
		scanf("%d%d%d", &stu.id, &stu.de, &stu.cai);
		stu.sum = stu.de + stu.cai;
		if (stu.de < l || stu.cai < l)
		{
			continue;
		}
		else if (stu.de >= h && stu.cai >= h)
		{
			v1.push_back(stu);
		}
		else if (stu.de >= h && stu.cai < h)
		{
			v2.push_back(stu);
		}
		else if (stu.de < h && stu.cai < h && stu.de >= stu.cai)
		{
			v3.push_back(stu);
		}
		else
		{
			v4.push_back(stu);
		}
	}

	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	sort(v3.begin(), v3.end(), cmp);
	sort(v4.begin(), v4.end(), cmp);

	cout << v1.size() + v2.size() + v3.size() + v4.size() << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		printf("%d %d %d\n", v1[i].id, v1[i].de, v1[i].cai);
	}

	for (int i = 0; i < v2.size(); i++)
	{
		printf("%d %d %d\n", v2[i].id, v2[i].de, v2[i].cai);
	}

	for (int i = 0; i < v3.size(); i++)
	{
		printf("%d %d %d\n", v3[i].id, v3[i].de, v3[i].cai);
	}

	for (int i = 0; i < v4.size(); i++)
	{
		printf("%d %d %d\n", v4[i].id, v4[i].de, v4[i].cai);
	}
	return 0;
}