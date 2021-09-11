#include <iostream>
using namespace std;

int main()
{
    long long t, a, b, c, sum;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c); // 只能用scanf来进行数据读取,cin读入溢出数会以最大值存储，而scanf会存储溢出数
        sum = a + b;                         // 必须用sum来存储结果，因为a+b会自动转换为unsigned进行比较
        if (a > 0 && b > 0 && sum < 0)       // 已经超出上限肯定大于c
            printf("Case #%d: true\n", i);
        else if (a < 0 && b < 0 && sum >= 0) // 已经超出下限肯定小于c
            printf("Case #%d: false\n", i);
        else if (sum > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}