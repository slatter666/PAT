#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int weight, index;
} list[10005];

vector<int> hats(10005);

bool cmp(node n1, node n2)
{
    return n1.weight > n2.weight;
}

int main()
{
    int n, num;
    cin >> n;
    for (int i = n; i >= 1; i--)
        cin >> hats[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        list[i] = {num, i};
    }

    vector<int> temp = hats;
    sort(temp.begin() + 1, temp.begin() + n + 1);

    sort(list + 1, list + n + 1, cmp);
    map<int, int> rec;
    for (int i = 1; i <= n; i++)
        rec[temp[i]] = n - i + 1;

    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            cout << " ";
        int rank = rec[hats[i]];
        cout << list[rank].index;
    }
}