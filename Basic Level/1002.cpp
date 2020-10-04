#include <iostream>
#include <string>
using namespace std;
int main()
{
    string table[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string str;
    cin >> str;
    int sum = 0;
    for (char c : str)
        sum += c - '0';

    string s = to_string(sum);
    for (int i = 0; i < s.size(); i++)
    {
        if (i != s.size() - 1)
            cout << table[s[i] - '0'] << " ";
        else
            cout << table[s[i] - '0'] << endl;
    }
    return 0;
}