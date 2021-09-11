#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0; //记录单词个数
    char word[30][10][10];
    string str;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> word[i][j][k];
            }
        }
    }

    getchar();
    getline(cin, str);
    vector<string> rec;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            temp.push_back(str[i]);
        else if (temp.size() > 0)
        {
            rec.push_back(temp);
            temp = "";
        }
    }
    if (temp.size() > 0)
        rec.push_back(temp);

    for (int i = 0; i < rec.size(); i++)
    {
        string Stemp = rec[i];
        if (i != 0) // 单词之间隔一行
            cout << endl;
        for (int j = 0; j < 7; j++) // 7行5列
        {
            for (int k = 0; k < Stemp.size(); k++)
            {
                for (int s = 0; s < 5; s++)
                {
                    cout << word[Stemp[k] - 'A'][j][s];
                }
                if (k != Stemp.size() - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}