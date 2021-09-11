#include <iostream>
#include <algorithm>
using namespace std;

string add(string s)
{
    int c = 0;
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        int rec = s[i] - '0' + s[s.size() - 1 - i] - '0' + c;
        int cur = rec % 10;
        c = rec / 10;
        result.insert(0, 1, cur + '0');
    }
    if (c == 1)
        result.insert(0, 1, '1');
    return result;
}

int main()
{
    string s1, s2;
    bool flag = false;
    cin >> s1;
    for (int i = 0; i < 10; i++)
    {
        s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2)
        {
            printf("%s is a palindromic number.\n", s2.c_str());
            flag = true;
            break;
        }
        else
        {
            string temp = add(s1);
            printf("%s + %s = %s\n", s2.c_str(), s1.c_str(), temp.c_str());
            s1 = temp;
        }
    }
    if (!flag)
        printf("Not found in 10 iterations.\n");
    return 0;
}