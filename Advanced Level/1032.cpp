#include <iostream>
using namespace std;

struct node
{
    char data;
    int next;
    bool flag = false;
} list[100000];

int main()
{
    int addr1, addr2, n, addr, next;
    char data;
    cin >> addr1 >> addr2 >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> addr >> data >> next;
        list[addr].data = data;
        list[addr].next = next;
    }

    for (int i = addr1; i != -1; i = list[i].next)
        list[i].flag = true;

    for (int i = addr2; i != -1; i = list[i].next)
    {
        if (list[i].flag == true) // 如果是true，那么后面的都一样了，因为next后面都是一样的了，对于passage和big这种两个g是不作为同一个字母存储的，那么next也是不一样的
        {
            printf("%05d\n", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}