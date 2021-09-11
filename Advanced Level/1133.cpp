#include <iostream>
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

    vector<node> rec;
    for (int i = head; i != -1; i = list[i].next) // 先加入负数
        if (list[i].data < 0)
            rec.push_back(list[i]);

    for (int i = head; i != -1; i = list[i].next) // 再加入[0,k]区间中的数
        if (list[i].data >= 0 && list[i].data <= k)
            rec.push_back(list[i]);

    for (int i = head; i != -1; i = list[i].next) // 最后加入大于k的数
        if (list[i].data > k)
            rec.push_back(list[i]);

    for (int i = 0; i < rec.size(); i++)
    {
        printf("%05d %d ", rec[i].addr, rec[i].data);
        if (i != rec.size() - 1)
            printf("%05d\n", rec[i + 1].addr);
        else
            printf("-1\n");
    }
    return 0;
}