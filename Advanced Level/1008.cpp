#include <iostream>
using namespace std;

int main()
{
    int n, front = 0, total = 0; //front上一次请求的层数, total记录总时间
    cin >> n;
    int req[n];
    for (int i = 0; i < n; i++)
        cin >> req[i];

    for (int i = 0; i < n; i++)
    {
        if (req[i] > front)
            total += (req[i] - front) * 6 + 5;
        else
            total += (front - req[i]) * 4 + 5;
        front = req[i];
    }
    cout << total << endl;
    return 0;
}