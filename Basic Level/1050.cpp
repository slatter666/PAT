#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int check(int number)
{
    int sq = sqrt(number);
    while (number % sq != 0)
        sq--;
    return sq;
}

int main()
{
    int n, index = 0;
    cin >> n;
    int num[n];
    int col = check(n);              //列
    int row = n / col;               //行 row >= col
    int layer = col * 1.0 / 2 + 0.5; //层数
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n, cmp);
    int rec[row][col];
    for (int i = 0; i < layer; i++) //内循环加上index <= n - 1这个判断是由于存在5行1列这种情况,如果不判断就会出现数组访问越界
    {
        for (int j = i; j < col - i && index <= n - 1; j++)
            rec[i][j] = num[index++];
        for (int j = i + 1; j < row - i && index <= n - 1; j++)
            rec[j][col - i - 1] = num[index++];
        for (int j = col - 2 - i; j >= i && index <= n - 1; j--)
            rec[row - 1 - i][j] = num[index++];
        for (int j = row - 2 - i; j > i && index <= n - 1; j--)
            rec[j][i] = num[index++];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j != 0)
                cout << " ";
            cout << rec[i][j];
        }
        cout << endl;
    }
    return 0;
}