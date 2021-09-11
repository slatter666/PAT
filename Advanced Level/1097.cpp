#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int addr, key, next;
} list[100000];

int main()
{
    int head, n, a, k, ne;
    cin >> head >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> k >> ne;
        list[a] = {a, k, ne};
    }

    bool rec[10005] = {0};
    vector<node> result, remove;
    for (int i = head; i != -1; i = list[i].next)
    {
        if (rec[abs(list[i].key)]) // 已经存在该值则加入移除链表,注意该题是判断绝对值
            remove.push_back(list[i]);
        else // 还未存在该值则加入result链表
        {
            result.push_back(list[i]);
            rec[abs(list[i].key)] = true;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        printf("%05d %d ", result[i].addr, result[i].key);
        if (i != result.size() - 1)
            printf("%05d\n", result[i + 1].addr);
        else
            printf("-1\n");
    }

    for (int i = 0; i < remove.size(); i++)
    {
        printf("%05d %d ", remove[i].addr, remove[i].key); // 注意这几行result和remove不要写混了
        if (i != remove.size() - 1)
            printf("%05d\n", remove[i + 1].addr);
        else
            printf("-1\n");
    }
    return 0;
}