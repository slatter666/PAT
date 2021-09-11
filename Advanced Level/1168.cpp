#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
    if (x <= 3)
        return x >= 2;
    else if (x % 6 != 1 && x % 6 != 5)
        return false;

    int sq = sqrt(x);
    for (int i = 5; i <= sq; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    bool flag = true;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        string temp = str.substr(i);
        cout << temp << " ";
        if (isPrime(stoi(temp)))
            cout << "Yes" << endl;
        else
        {
            flag = false;
            cout << "No" << endl;
        }
    }
    if (flag)
        cout << "All Prime!" << endl;
    return 0;
}