#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int panda[n], milk1[n], milk2[n];
    for (int i = 0; i < n; i++)
        cin >> panda[i];

    milk1[0] = 200;
    for (int i = 1; i < n; i++)
    {
        if (panda[i] > panda[i - 1])
            milk1[i] = milk1[i - 1] + 100;
        else if (panda[i] == panda[i - 1])
            milk1[i] = milk1[i - 1];
        else
            milk1[i] = 200;
    }

    milk2[n - 1] = 200;
    sum += max(milk1[n - 1], milk2[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (panda[i] > panda[i + 1])
            milk2[i] = milk2[i + 1] + 100;
        else if (panda[i] == panda[i + 1])
            milk2[i] = milk2[i + 1];
        else
            milk2[i] = 200;
        sum += max(milk1[i], milk2[i]);
    }
    cout << sum << endl;
    return 0;
}