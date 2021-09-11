#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int addr, data, next;
} list[100000];

int main()
{
    int first, n, k, a, d, ne;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> d >> ne;
        list[a] = {a, d, ne};
    }

    vector<node> temp;
    vector<vector<node>> rec;
    for (int i = first; i != -1; i = list[i].next)
    {
        temp.push_back(list[i]);
        if (temp.size() == k)
        {
            rec.push_back(temp);
            temp.clear();
        }
    }
    rec.push_back(temp);

    temp.clear();
    for (int i = rec.size() - 1; i >= 0; i--)
        for (int j = 0; j < rec[i].size(); j++)
            temp.push_back(rec[i][j]);

    for (int i = 0; i < temp.size(); i++)
    {
        printf("%05d %d ", temp[i].addr, temp[i].data);
        if (i != temp.size() - 1)
            printf("%05d\n", temp[i + 1].addr);
        else
            printf("-1\n");
    }
    return 0;
}