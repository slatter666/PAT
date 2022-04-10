#include <iostream>
using namespace std;

int main()
{
    int tsize, m, n, num, result = 0;
    cin >> tsize >> m >> n;
    int table[tsize];
    fill(table, table + tsize, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int key = num % m;
        for (int j = 0; j < tsize; j++)
        {
            int index = (key + j) % tsize;
            if (table[index] == -1)
            {
                table[index] = num;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool flag = false; // 记录能否找到-1,找不到-1说明要找整个表,次数为tsize+1
        for (int j = 0; j < tsize; j++)
        {
            result++;
            int index = (i + j) % tsize;
            if (table[index] == -1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            result++;
    }
    printf("%.1f\n", result * 1.0 / m);
    return 0;
}