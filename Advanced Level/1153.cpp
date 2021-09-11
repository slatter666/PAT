#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct card
{
    string num;
    int score;
};

bool cmp(card c1, card c2)
{
    if (c1.score != c2.score)
        return c1.score > c2.score;
    else
        return c1.num < c2.num;
}

int main()
{
    int n, m, type;
    string term;
    cin >> n >> m;
    vector<card> rec(n);
    for (int i = 0; i < n; i++)
        cin >> rec[i].num >> rec[i].score;

    for (int i = 1; i <= m; i++)
    {
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        int count = 0, total = 0;
        vector<card> temp;
        if (type == 1)
        {
            for (int j = 0; j < rec.size(); j++)
            {
                if (rec[j].num.substr(0, 1) == term)
                    temp.push_back(rec[j]);
            }
        }
        else if (type == 2)
        {
            for (int j = 0; j < rec.size(); j++)
            {
                if (rec[j].num.substr(1, 3) == term)
                {
                    count++;
                    total += rec[j].score;
                }
            }
            if (count > 0)
                printf("%d %d\n", count, total);
        }
        else if (type == 3)
        {
            unordered_map<string, int> query3;
            for (int j = 0; j < rec.size(); j++)
            {
                if (rec[j].num.substr(4, 6) == term)
                    query3[rec[j].num.substr(1, 3)]++;
            }
            for (auto it : query3) // 因为和card结构体类型相同且排序规则一样就顺便往里面存了
                temp.push_back({it.first, it.second});
        }
        sort(temp.begin(), temp.end(), cmp);
        for (int j = 0; j < temp.size(); j++)
            printf("%s %d\n", temp[j].num.c_str(), temp[j].score);
        if (((type == 1 || type == 3) && temp.size() == 0) || (type == 2 && count == 0))
            printf("NA\n");
    }
    return 0;
}