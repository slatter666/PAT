#include <iostream>
#include <cmath>
using namespace std;

long long convert(string s, int scale)
{
    long long result = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
            result += (s[i]-'0') * pow(scale, s.size() - 1 - i);
        else //s[i]>='a' && s[i]<='z'
            result += (s[i] - 'a' + 10) * pow(scale, s.size() - 1 - i);
    }
    return result;
}

int getMax(string s)
{
    int rec = 10;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            rec = s[i] - 'a' + 10;
    }
    return rec;
}

int main()
{
    string n1, n2, temp;
    long long tag, radix, num, max_radix, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    bool flag = false;
    if (tag == 1)
    {
        num = convert(n1, radix);
        max_radix = getMax(n2);
        temp = n2;
    }
    else
    {
        num = convert(n2, radix);
        max_radix = getMax(n1);
        temp = n1;
    }

    for (int i = max_radix; i >= 2; i--)
    {
        long long result = convert(temp, i);
        if (result == num)
        {
            flag = true;
            result_radix = i;
            break;
        }
    }

    if (flag)
        cout << result_radix << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}