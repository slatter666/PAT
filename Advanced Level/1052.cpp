#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int addr, key, next;
    bool flag = false;
} list[100000];

bool cmp(node n1, node n2)
{
    if (n1.flag && n2.flag) // 两个均是链表元素,这里把两个都打成了n1，找了好久的bug，淦
        return n1.key < n2.key;
    else
        return n1.flag > n2.flag;
}

int main()
{
    int n, head, a, k, ne, cnt = 0;
    cin >> n >> head;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> k >> ne;
        list[a] = {a, k, ne};
    }

    for (int i = head; i != -1; i = list[i].next, cnt++)
        list[i].flag = true;

    sort(list, list + 100000, cmp);
    if (cnt == 0)
        printf("0 -1\n");
    else
    {
        printf("%d %05d\n", cnt, list[0].addr);
        for (int i = 0; i < cnt; i++)
        {
            printf("%05d %d ", list[i].addr, list[i].key);
            if (i != cnt - 1)
                printf("%05d\n", list[i + 1].addr);
            else
                printf("-1\n");
        }
    }
    return 0;
}