#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct node
{
    int start, end;
};

int n, m, k, v1, v2;
vector<node> edge;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        edge.push_back({v1, v2});
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        bool flag = true;
        vector<int> color(n);
        set<int> rec;
        for (int j = 0; j < n; j++)
        {
            cin >> color[j];
            rec.insert(color[j]);
        }
        for (int j = 0; j < m && flag; j++)
        {
            v1 = edge[j].start, v2 = edge[j].end;
            if (color[v1] == color[v2])
                flag = false;
        }
        if (flag)
            printf("%d-coloring\n", rec.size());
        else
            printf("No\n");
    }
    return 0;
}