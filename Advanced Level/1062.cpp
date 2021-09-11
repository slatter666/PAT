#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    string id;
    int virtue;
    int talent;
};

bool cmp(node n1, node n2)
{
    if ((n1.virtue + n1.talent) != (n2.virtue + n2.talent))
        return (n1.virtue + n1.talent) > (n2.virtue + n2.talent);
    else if (n1.virtue != n2.virtue)
        return n1.virtue > n2.virtue;
    else
        return n1.id < n2.id; // 这里之前少写了个return找了好久的错
}

int main()
{
    int n, l, h, cnt = 0;
    cin >> n >> l >> h;
    node temp;
    vector<node> rec[4]; // sage, noble, foolmen, smallmen
    for (int i = 0; i < n; i++)
    {
        cin >> temp.id >> temp.virtue >> temp.talent;
        if (temp.virtue < l || temp.talent < l)
            cnt++;
        else if (temp.virtue >= h && temp.talent >= h)
            rec[0].push_back(temp);
        else if (temp.virtue >= h && temp.talent < h)
            rec[1].push_back(temp);
        else if (temp.virtue < h && temp.talent < h && temp.virtue >= temp.talent)
            rec[2].push_back(temp);
        else
            rec[3].push_back(temp);
    }

    cout << n - cnt << endl;
    for (int i = 0; i < 4; i++)
    {
        sort(rec[i].begin(), rec[i].end(), cmp);
        for (int j = 0; j < rec[i].size(); j++)
            cout << rec[i][j].id << " " << rec[i][j].virtue << " " << rec[i][j].talent << endl;
    }
    return 0;
}