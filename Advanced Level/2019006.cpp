#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int addr, data, next;
} list[100005];

int main()
{
    int first, n, k, a, d, ne;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> d >> ne;
        list[a] = {a, d, ne};
    }

    vector<node> list1, list2, result;
    for (int i = first, j = 1; i != -1; i = list[i].next, j++)
    {
        if (j > k)
            list2.push_back(list[i]);
        else
            list1.push_back(list[i]);
    }

    while (!(list1.empty() && list2.empty()))
    {
        if (!list1.empty())
        {
            result.push_back(list1.back());
            list1.pop_back();
        }
        if (!list2.empty())
        {
            result.push_back(list2.back());
            list2.pop_back();
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        printf("%05d %d ", result[i].addr, result[i].data);
        if (i != result.size() - 1)
            printf("%05d\n", result[i + 1].addr);
        else
            printf("-1\n");
    }
    return 0;
}