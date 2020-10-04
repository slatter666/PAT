#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int m, n, tol, num;
int arr[1002][1002];
int pos[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
bool check(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int newx = x + pos[i][0];
		int newy = y + pos[i][1];
		if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && abs(arr[x][y] - arr[newx][newy]) <= tol)
			return false;
	}
	return true;
}

int main()
{
	map<int, int> rec;
	vector<pair<int, int>> vec;
	scanf("%d %d %d", &m, &n, &tol);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			rec[arr[i][j]]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (rec[arr[i][j]] == 1 && check(i, j))
				vec.push_back(pair<int, int>(i, j));
		}
	}

	if (vec.size() == 0)
		printf("Not Exist");
	else if (vec.size() > 1)
		printf("Not Unique");
	else
		printf("(%d, %d): %d", vec[0].second, vec[0].first, arr[vec[0].first][vec[0].second]);
	return 0;
}