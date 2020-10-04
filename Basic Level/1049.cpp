#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, index = 1;
    long double num, sum = 0;
    cin >> n;
    int last = n + 1;
    while (n--)
    {
        cin >> num;
        sum += num * index * (last - index);
        index++;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
}