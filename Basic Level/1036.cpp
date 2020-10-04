#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (i == 0 || i == (n - 1) / 2)
        {
            for (int j = 0; j < n; j++)
            {
                cout << c;
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 || j == n - 1)
                    cout << c;
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}