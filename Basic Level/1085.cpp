#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct grade
{
	int second = 0; //乙级
	int first = 0;	//甲级
	int top = 0;	//顶级
	int count = 0;	//学生人数
};

struct ranking
{
	string sc;
	int final = -1;
	int count;
} u[100005];

bool cmp(ranking r1, ranking r2)
{
	if (r1.final != r2.final)
		return r1.final > r2.final;
	else if (r1.count != r2.count)
		return r1.count < r2.count;
	else
		return r1.sc < r2.sc;
}
int main()
{
	int n, point, i;
	char id[10], school[10];
	string univ;
	map<string, grade> rec;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %s", id, &point, school);
		univ = school;
		transform(univ.begin(), univ.end(), univ.begin(), ::tolower);
		if (id[0] == 'B')
			rec[univ].second += point;
		else if (id[0] == 'A')
			rec[univ].first += point;
		else if (id[0] == 'T')
			rec[univ].top += point;
		rec[univ].count++;
	}

	cout << rec.size() << endl; //输出单位个数
	map<string, grade>::iterator it;
	for (it = rec.begin(), i = 1; it != rec.end(); it++, i++)
	{
		u[i].sc = it->first;
		u[i].final = it->second.second / 1.5 + it->second.first + it->second.top * 1.5;
		u[i].count = it->second.count;
	}

	int rank_num = 0, total = i - 1; //排名,学校总数
	sort(u + 1, u + total + 1, cmp);
	for (i = 1; i <= total; i++)
	{
		if (u[i].final != u[i - 1].final)
			rank_num = i - 0;
		cout << rank_num << " " << u[i].sc << " " << u[i].final << " " << u[i].count << endl;
	}
	return 0;
}