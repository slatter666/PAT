#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        res = res > sqrt(pow(a, 2) + pow(b, 2)) ? res : sqrt(pow(a, 2) + pow(b, 2));
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
    return 0;
}