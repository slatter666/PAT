#include <iostream>
using namespace std;

int main()
{
    int rec[40] = {0};
    int n, b, index = 0;
    cin >> n >> b;
    while (n / b != 0)
    {
        rec[index++] = n % b;
        n /= b;
    }
    rec[index] = n;

    int left = 0, right = index;
    bool flag = true;
    while (left <= right)
    {
        if (rec[left] == rec[right])
        {
            left++;
            right--;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = index; i >= 0; i--)
    {
        cout << rec[i];
        if (i != 0)
            cout << " ";
    }
    return 0;
}