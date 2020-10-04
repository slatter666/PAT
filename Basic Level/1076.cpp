#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ans, c, sign;
        for (int j = 0; j < 4; j++)
        {
            cin >> ans >> sign >> c;
            if (c == 'T')
                cout << ans - 'A' + 1;
        }
    }
    return 0;
}