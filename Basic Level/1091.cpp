#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, num, j;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        int square = pow(num, 2);
        int rec = pow(10, to_string(num).size());
        for (j = 1; j < 10; j++)
        {
            int result = j * square;
            if ((result - num) % rec == 0)
            {
                cout << j << " " << result << endl;
                break;
            }
        }
        if (j == 10)
            cout << "No" << endl;
    }
    return 0;
}