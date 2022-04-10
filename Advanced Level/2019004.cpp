#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
    int number;
    int ip = 0;
};

bool cmp(node n1, node n2)
{
    if (n1.ip != n2.ip)
        return n1.ip > n2.ip;
    return n1.number < n2.number;
}

int main()
{
    int n, m, p1, p2, k, v;
    cin >> n >> m;
    vector<pair<int, int>> relation;
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2;
        relation.push_back({p1, p2});
    }

    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        else
        {
            vector<node> res;
            map<int, int> degree;
            set<int> rec;
            for (int i = 0; i < k; i++)
            {
                cin >> v;
                rec.insert(v);
                degree[v] = 0; // 注意这里一定要每个点都放进map，否则第三个样例每个点都不存在于map中导致没有输出
            }

            for (int i = 0; i < relation.size(); i++)
            {
                p1 = relation[i].first, p2 = relation[i].second;
                if (rec.find(p1) != rec.end() && rec.find(p2) != rec.end())
                {
                    degree[p1]++;
                    degree[p2]++;
                }
            }

            for (auto it : degree)
                res.push_back({it.first, it.second});
            sort(res.begin(), res.end(), cmp);
            for (int i = 0; i < 3; i++)
            {
                if (i != 0)
                    cout << " ";
                cout << res[i].number;
            }
            cout << endl;
        }
    }
    return 0;
}