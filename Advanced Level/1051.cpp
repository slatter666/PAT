#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int m, n, k, pos;
    cin >> m >> n >> k;
    int arr[n + 1];
    for (int i = 0; i < k; i++)
    {
        pos = 0;
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        stack<int> s;
        for (int j = 1; j <= n; j++)
        {
            s.push(j);
            if (s.size() > m) // 这个判断语句顺序不能写错
                break;
            while (!s.empty() && s.top() == arr[pos]) // 这里一定要把s.empty()写在前面，否则如果栈为空会出现段错误
            {
                s.pop();
                pos++;
            }
        }
        if (s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}