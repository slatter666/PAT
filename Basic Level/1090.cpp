#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	vector<vector<int>> vec(100005);
	int n, m, k, good0, good1, good2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &good0, &good1);
		vec[good0].push_back(good1);
		vec[good1].push_back(good0);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		bool flag = false;
		set<int> s;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &good2);
			s.insert(good2);
		}

		set<int>::iterator it;
		for (it = s.begin(); it != s.end(); it++)
		{
			for (int j = 0; j < vec[(*it)].size(); j++)
			{
				if (s.find(vec[(*it)][j]) != s.end())
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				printf("No\n");
				break;
			}
		}

		if (!flag)
			printf("Yes\n");
	}
	return 0;
}