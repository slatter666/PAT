#include <iostream>
#include <queue>
using namespace std;

struct mouse
{
	int weight;
	int rank;
} mice[1005];

int main()
{
	int np, ng, group, total, order;
	cin >> np >> ng;
	for (int i = 0; i < np; i++)
		cin >> mice[i].weight;

	queue<int> q;
	for (int i = 0; i < np; i++)
	{
		cin >> order;
		q.push(order);
	}

	total = np; // 当前一轮总人数
	while (q.size() != 1)
	{
		if (total % ng == 0)
			group = total / ng;
		else
			group = total / ng + 1;

		for (int i = 0; i < group; i++)
		{
			int winner = q.front();
			for (int j = 0; j < ng; j++)
			{
				if (i * ng + j >= total) // 当前一轮比赛结束
					break;
				int current = q.front();
				if (mice[current].weight > mice[winner].weight)
					winner = current;
				mice[current].rank = group + 1; // 共有group组的老鼠，每组晋级一个，即最终这一轮能晋级的是group个老鼠，那么没有晋级的所有人就是group+1名
				q.pop();
			}
			q.push(winner);
		}
		total = group; // 新一轮人数
	}
	mice[q.front()].rank = 1; // 第一名

	for (int i = 0; i < np; i++)
	{
		cout << mice[i].rank;
		if (i != np - 1)
			cout << " ";
	}
	return 0;
}