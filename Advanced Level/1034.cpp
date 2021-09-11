#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k, t, idNumber = 1;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> result;
int graph[2005][2005], weight[2005]; // 测试点3段错误原因：数组开小了，1000条通话记录可以产生2000个人
bool visit[2005];

int convert(string s)
{
	if (stringToInt[s] == 0)
	{
		stringToInt[s] = idNumber;
		intToString[idNumber] = s;
		return idNumber++; // 返回的是idNumber，之后再做的自增
	}
	else
		return stringToInt[s];
}

void dfs(int u, int &head, int &member, int &totalWeight)
{
	visit[u] = true;
	member++;
	if (weight[u] > weight[head])
		head = u;
	for (int i = 1; i < idNumber; i++)
	{
		if (graph[u][i] > 0) // 这里不能写成(graph[u][i] > 0 && visit[i]==false)的原因在于如果存在1-2,2-3,3-1的路径那么3-1的time是需要算的，而写成这样就算不了了
		{
			totalWeight += graph[u][i];
			graph[u][i] = graph[i][u] = 0; // 避免同一条路径权重被算两次
			if (visit[i] == false)
				dfs(i, head, member, totalWeight);
		}
	}
}

void solve()
{
	for (int i = 1; i < idNumber; i++)
	{
		if (visit[i] == false)
		{
			int head = i, member = 0, totalWeight = 0;
			dfs(i, head, member, totalWeight);
			if (member > 2 && totalWeight > k)
				result[intToString[head]] = member;
		}
	}
}

int main()
{
	string name1, name2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2 >> t;
		int id1 = convert(name1);
		int id2 = convert(name2);
		graph[id1][id2] += t;
		graph[id2][id1] += t;
		weight[id1] += t;
		weight[id2] += t;
	}

	solve();
	cout << result.size() << endl;
	for (auto it : result)
		cout << it.first << " " << it.second << endl;
	return 0;
}