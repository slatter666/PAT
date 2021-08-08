#include <iostream>
using namespace std;

int main()
{
    int n, t, cnt;
    int rec[100005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        rec[t] = i; // t数字占据的哪个位置
    }

    for (int i = 1; i < n; i++)
    {
        if (i != rec[i])
        {
            while (rec[0] != 0)
            {
                swap(rec[0], rec[rec[0]]); // 让一个数字归位，0号数字所占据的位置让出来给本该占据该位置的数
                cnt++;
            }
            if (i != rec[i])
            { // 总会将该位置还原成功的
                swap(rec[0], rec[i]);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}