#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node
{
    string id;
    int gp = -1, gmid = -1, gfinal = -1, g = -1;
};

int p, m, n;
map<string, node> rec;
vector<node> result;

bool cmp(node n1, node n2)
{
    if (n1.g != n2.g)
        return n1.g > n2.g;
    else
        return n1.id < n2.id;
}

int main()
{
    string name;
    int score;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++)
    {
        cin >> name >> score;
        if (score >= 200)
            rec[name].gp = score;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> name >> score;
        if (rec.find(name) != rec.end())
            rec[name].gmid = score;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        if (rec.find(name) != rec.end())
        {
            rec[name].gfinal = score;
            if (rec[name].gmid > rec[name].gfinal)
                rec[name].g = rec[name].gmid * 0.4 + rec[name].gfinal * 0.6 + 0.5;
            else
                rec[name].g = rec[name].gfinal;
        }
    }

    for (auto it : rec)
    {
        if (it.second.g >= 60)
        {
            it.second.id = it.first;
            result.push_back(it.second);
        }
    }
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++)
        cout << result[i].id << " " << result[i].gp << " " << result[i].gmid << " " << result[i].gfinal << " " << result[i].g << endl;
    return 0;
}