#include <iostream>
#include <string>
using namespace std;

string s;
int length;
string first[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string second[] = {"   ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void fun1(int num)
{
    if (num / 13)
        cout << second[num / 13];
    if ((num / 13) && (num % 13))
        cout << " ";
    if (num % 13 || num == 0)
        cout << first[num % 13];
}

void fun2()
{
    int t1 = 0, t2 = 0;
    string s2, s1 = s.substr(0, 3);
    if (length > 4)
        s2 = s.substr(4, 3);
    for (int i = 1; i <= 12; i++)
    {
        if (s1 == first[i] || s2 == first[i])
            t2 = i;
        if (s1 == second[i])
            t1 = i;
    }
    cout << t1 * 13 + t2;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, s);
        length = s.size();
        if (s[0] >= '0' && s[0] <= '9')
            fun1(stoi(s));
        else
            fun2();
        cout << endl;
    }
    return 0;
}