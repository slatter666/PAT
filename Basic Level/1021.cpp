#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    int num[10];
    memset(num, 0, sizeof(num));
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        num[str[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (num[i] != 0)
            cout << i << ":" << num[i] << endl;
    }
    return 0;
}