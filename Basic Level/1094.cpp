#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 3)
        return num > 1;
    else if (num % 6 != 5 && num % 6 != 1)
        return false;

    int sq = sqrt(num);
    for (int i = 5; i <= sq + 1; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int l, k;
    cin >> l >> k;
    string str;
    cin >> str;
    if (k > l) //最开始遗忘了这种情况,当k>l的时候肯定是无解的
        cout << "404" << endl;
    else
    {
        for (int i = 0; i <= l - k; i++)
        {
            string temp = str.substr(i, k);
            int num = stoi(temp);
            if (isPrime(num))
            {
                cout << temp << endl;
                break;
            }
            if (i == l - k)
                cout << "404" << endl;
        }
    }
    return 0;
}