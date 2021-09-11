#include <iostream>
using namespace std;

int main()
{
    int n, minlen = 300;
    string str[105];
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
        if (str[i].size() < minlen)
            minlen = str[i].size();
    }

    string kuchiguse;
    for (int i = 1; i <= minlen; i++)   // 此处必须是等于,用于确定全长都一样
    {
        bool flag = true;
        string temp = str[0].substr(str[0].size() - i);
        for (int j = 1; j < n; j++)
        {
            if (str[j].substr(str[j].size() - i) != temp)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            kuchiguse = temp;
        else
            break;
    }

    if (kuchiguse.size() == 0)
        cout << "nai" << endl;
    else
        cout << kuchiguse << endl;
    return 0;
}