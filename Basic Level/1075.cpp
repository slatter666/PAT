#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	vector<pair<int, int>> result;
	int first, n, k, addr;
	int data[100005], next[100005], list[100005]; //list存储顺序
	scanf("%d %d %d", &first, &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &addr);
		scanf("%d %d", &data[addr], &next[addr]);
	}

	while (first != -1)
	{
		vec.push_back(pair<int, int>(first, data[first]));
		first = next[first];
	}

	int len = vec.size(); //测试点4会存在不属于链表的结点,所以循环判断不能用n而用vec长度,详细分析请看https://blog.csdn.net/bawangtu/article/details/81501723
	for (int i = 0; i < len; i++)
	{
		if (vec[i].second < 0)
			result.push_back(vec[i]);
	}

	for (int i = 0; i < len; i++)
	{
		if (vec[i].second >= 0 && vec[i].second <= k)
			result.push_back(vec[i]);
	}

	for (int i = 0; i < len; i++)
	{
		if (vec[i].second > k)
			result.push_back(vec[i]);
	}

	for (int i = 0; i < len - 1; i++)
		printf("%05d %d %05d\n", result[i].first, result[i].second, result[i + 1].first);
	printf("%05d %d -1\n", result[len - 1].first, result[len - 1].second);
	return 0;
}