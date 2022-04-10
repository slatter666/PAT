#include <iostream>
#include <cmath>
using namespace std;

int n, maxA;

bool check(int A, int B)
{
    for (int i = 0; i < n; i++)
    {
        if (B * B / 1000 != A)
            return false;
        A++;
        B++;
    }
    return true;
}

int main()
{
    bool flag = false;
    cin >> n >> maxA;
    for (int i = 1; i <= maxA; i++)
    {
        for (int j = sqrt(i * 1000); j <= sqrt((i + 1) * 1000); j++)
        {
            if (check(i, j))
            {
                flag = true;
                cout << i << " " << j << endl;
            }
        }
    }
    if (flag == false)
        cout << "No Solution." << endl;
    return 0;
}