#include <iostream>
#include <vector>
#include <map>
using namespace std;

int tree[1005];

void adjust(int index)
{
    int t = index / 2;
    while (t >= 1 && tree[t] < tree[index])
    {
        swap(tree[t], tree[index]);
        index = t;
        t /= 2;
    }
}

vector<string> split(string s)
{
    vector<string> res;
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            res.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(s[i]);
    }
    res.push_back(temp);
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
        adjust(i);
    }

    map<int, int> rec;
    for (int i = 1; i <= n; i++)
        rec[tree[i]] = i;

    string result;
    getchar();
    for (int i = 0; i < m; i++)
    {
        bool flag = true;
        string str;
        getline(cin, str);
        vector<string> statement = split(str);
        if (statement[1] == "and")
        {
            int x = stoi(statement[0]), y = stoi(statement[2]);
            if (rec[x] / 2 != rec[y] / 2)
                flag = false;
        }
        else if (statement[3] == "root")
        {
            int x = stoi(statement[0]);
            if (rec[x] != 1)
                flag = false;
        }
        else if (statement[3] == "parent")
        {
            int x = stoi(statement[0]), y = stoi(statement[5]);
            if (rec[x] != rec[y] / 2)
                flag = false;
        }
        else if (statement[3] == "left")
        {
            int x = stoi(statement[0]), y = stoi(statement[6]);
            if (rec[x] != rec[y] * 2)
                flag = false;
        }
        else if (statement[3] == "right")
        {
            int x = stoi(statement[0]), y = stoi(statement[6]);
            if (rec[x] != rec[y] * 2 + 1)
                flag = false;
        }

        if (flag)
            result += '1';
        else
            result += '0';
    }
    cout << result << endl;
    return 0;
}