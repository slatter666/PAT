#include <iostream>
#include <vector>
using namespace std;

struct node
{
	string data;
	int left, right;
};

int n, root = 1;
vector<node> rec;

string dfs(int index)
{
	if (index == -1)
		return "";
	if (rec[index].right != -1)
	{
		rec[index].data = dfs(rec[index].left) + rec[index].data + dfs(rec[index].right);
		if (index != root)
			rec[index].data = '(' + rec[index].data + ')';
	}
	return rec[index].data;
}

int main()
{
	cin >> n;
	rec.resize(n + 1);
	bool visit[n + 1] = {0};
	for (int i = 1; i <= n; i++)
	{
		cin >> rec[i].data >> rec[i].left >> rec[i].right;
		if (rec[i].left != -1) // 左孩子或者右孩子一定不是根
			visit[rec[i].left] = true;
		if (rec[i].right != -1)
			visit[rec[i].right] = true;
	}

	while (visit[root])
		root++;
	cout << dfs(root) << endl;
	return 0;
}