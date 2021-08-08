#include <iostream>
#include <algorithm>
using namespace std;

string ope(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    int carry = 0;
    string stemp = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int temp = s[i] - '0' + s1[i] - '0' + carry;
        stemp.insert(0, to_string(temp % 10));
        carry = temp / 10;
    }
    if (carry != 0)
        stemp.insert(0, to_string(carry));
    return stemp;
}

bool check(string s)
{
    int left = 0, right = s.size() - 1;
    while (left <= right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    int num, step, count = 0;
    bool flag = false;
    string str;
    cin >> str >> step;
    while (count < step)
    {
        if (check(str))
        {
            flag = true;
            break;
        }
        else
            str = ope(str);
        count++;
    }
    cout << str << endl;
    cout << count << endl;
    return 0;
}