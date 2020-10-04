#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    bool rec[128] = {0}; //检测是否已经被检查过
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++)
    {
        if (rec[(int)str1[i]])
            continue;
        else
        {
            bool flag = false;
            for (int j = 0; j < str2.size(); j++)
            {
                if (str1[i] == str2[j])
                {
                    rec[(int)str1[i]] = 1;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                if ((str1[i] >= '0' && str1[i] <= '9') || str1[i] == '_')
                {
                    cout << str1[i];
                    rec[(int)str1[i]] = 1;
                }
                else if (str1[i] >= 'A' && str1[i] <= 'Z')
                {
                    cout << str1[i];
                    rec[(int)str1[i]] = 1;
                    rec[str1[i] + 32] = 1;
                }
                else if (str1[i] >= 'a' && str1[i] <= 'z')
                {
                    cout << (char)(str1[i] - 32);
                    rec[(int)str1[i]] = 1;
                    rec[str1[i] - 32] = 1;
                }
            }
        }
    }
    return 0;
}