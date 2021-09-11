#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    string name;
    int age;
    int worth;
};

bool cmp(node n1, node n2)
{
    if (n1.worth != n2.worth)
        return n1.worth > n2.worth;
    else if (n1.age != n2.age)
        return n1.age < n2.age;
    else
        return n1.name < n2.name;
}

int main()
{
    int n, k, m, amin, amax;
    cin >> n >> k;
    vector<node> rec(n);
    for (int i = 0; i < n; i++)
        cin >> rec[i].name >> rec[i].age >> rec[i].worth;

    sort(rec.begin(), rec.end(), cmp);
    for (int i = 1; i <= k; i++)
    {
        printf("Case #%d:\n", i);
        cin >> m >> amin >> amax;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (rec[i].age >= amin && rec[i].age <= amax && cnt < m)
            {
                cout << rec[i].name << " " << rec[i].age << " " << rec[i].worth << endl;
                cnt++;
            }
            if (cnt == m)
                break;
        }
        if (cnt == 0)
            cout << "None" << endl;
    }
    return 0;
}