#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getRow(int num)
{
    int temp = sqrt(num);
    while (true)
    {
        if (num % temp == 0)
            return num / temp;
        temp--;
    }
}

int main()
{
    int n, row, col;
    int arr[10005];
    cin >> n;
    row = getRow(n);           // 计算行数
    col = n / row;             // 计算列数
    int rec[row + 2][col + 2]; // 其实rec[row+1][col+1]也完全ok，无所谓，开到能放下就行了
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); // 排序
    int top = 1, left = 1, right = col, bottom = row, cnt = n - 1;
    while (cnt >= 0)
    {
        for (int i = left; i <= right && cnt >= 0; i++) // 上
            rec[top][i] = arr[cnt--];
        top += 1;

        for (int i = top; i <= bottom && cnt >= 0; i++) // 右
            rec[i][right] = arr[cnt--];
        right -= 1;

        for (int i = right; i >= left && cnt >= 0; i--) // 下
            rec[bottom][i] = arr[cnt--];
        bottom -= 1;

        for (int i = bottom; i >= top && cnt >= 0; i--) // 左 其他不判断cnt>=0，此处加个判断left<right也行，因为有可能最终的一轮只输出一列，如3 1 2 3，如果不判断left<right，此处会逆填充导致错误
            rec[i][left] = arr[cnt--];
        left += 1;
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << rec[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}