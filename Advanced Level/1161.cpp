#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int addr, data, next;
} list0[100000];

vector<node> list1, list2;

int main()
{
    int l1, l2, n, a, d, ne, tag = 1;
    cin >> l1 >> l2 >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> d >> ne;
        list0[a] = {a, d, ne};
    }

    for (int i = l1; i != -1; i = list0[i].next)
        list1.push_back(list0[i]);
    for (int i = l2; i != -1; i = list0[i].next)
        list2.push_back(list0[i]);
    if (list1.size() < list2.size())
        swap(list1, list2); // 保证list1最长

    vector<node> result;
    for (int i = 0, j = list2.size() - 1; i < list1.size(); i++)
    {
        if (i != 0 && i % 2 == 0 && j >= 0)
            result.push_back(list2[j--]);
        result.push_back(list1[i]);
        if (i == list1.size() - 1 && j == 0)
            result.push_back(list2[j]);
    }

    for (int i = 0; i < result.size(); i++)
    {
        printf("%05d %d ", result[i].addr, result[i].data);
        if (i != result.size() - 1)
            printf("%05d\n", result[i + 1].addr);
        else
            printf("-1\n");
    }
}