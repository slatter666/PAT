#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int addr, data, next;
} list[100000];

int main()
{
	int head, n, k, a, d, ne;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> d >> ne;
		list[a] = {a, d, ne};
	}

	vector<node> arraylist; // 记录链表
	for (int i = head; i != -1; i = list[i].next)
		arraylist.push_back(list[i]);

	for (int i = 0; i < arraylist.size() / k; i++)
		reverse(arraylist.begin() + k * i, arraylist.begin() + k * (i + 1));

	for (int i = 0; i < arraylist.size(); i++)
	{
		printf("%05d %d ", arraylist[i].addr, arraylist[i].data);
		if (i != arraylist.size() - 1)
			printf("%05d\n", arraylist[i + 1].addr);
		else
			printf("-1\n");
	}
	return 0;
}