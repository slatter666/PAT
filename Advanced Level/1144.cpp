#include <iostream>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    bool rec[100005] = {0}; // 最多10000个数，这个数组不可能放得满，肯定能找到最小值
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > 0 && num < 100005)
            rec[num] = true;
    }

    for (int i = 1; i < 100005; i++)
    {
        if (rec[i] == false)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}