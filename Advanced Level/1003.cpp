#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 505, INF = 0x3f3f3f3f;
int n, m, c1, c2, t1, t2, len, count = 0; //城市数、路径数、出发点、终点
int rescue[MAX], dist[MAX];				  //各个地区救援队伍数、起点到其他位置的最短路径
int path[MAX][MAX];
bool visit[MAX] = {0};				  //是否遍历
int num[MAX] = {0}, total[MAX] = {0}; //到各个地区能集结的队伍数、路径条数
void dijk()
{
	num[c1] = rescue[c1];
	dist[c1] = 0;
	total[c1] = 1;
	for (int i = 0; i < n; i++)
	{
		int v = -1;
		for (int j = 0; j < n; j++)
		{
			if (!visit[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		}

		visit[v] = true;
		for (int j = 0; j < n; j++)
		{
			if (j == v)
				continue;
			if (dist[j] == dist[v] + path[v][j])
			{
				total[j] += total[v];
				num[j] = max(num[j], num[v] + rescue[j]);
			}

			if (dist[j] > dist[v] + path[v][j])
			{
				total[j] = total[v];
				num[j] = max(num[j], num[v] + rescue[j]);
				dist[j] = dist[v] + path[v][j];
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	fill(dist, dist + MAX, INF);
	for (int i = 0; i < n; i++)
		scanf("%d", &rescue[i]);

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == j)
				path[i][j] = 0;
			else
				path[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &len);
		path[t1][t2] = len;
		path[t2][t1] = len;
	}

	dijk();
	printf("%d %d\n", total[c2], num[c2]);
}