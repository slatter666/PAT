#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, v1, v2, k, num;
	cin >> n >> m;
	vector<int> in(n + 1, 0); // 存储每个结点的入度
	vector<vector<int>> vertice(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		vertice[v1].push_back(v2);
		in[v2]++;
	}

	bool control = 1; // 控制输出
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		bool judge = true;
		vector<int> temp = in;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			if (temp[num] != 0)
				judge = false;
			for (int t : vertice[num])
				temp[t]--;
		}
		if (judge)
			continue;
		if (control)
		{
			cout << i;
			control = false;
		}
		else
			cout << " " << i;
	}
	return 0;
}