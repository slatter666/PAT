#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
string id;
unordered_map<string, bool> alumnus;

int main()
{
    int cnt = 0, birthday = 30000000;
    string oldestAlumnu, oldestGuest;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        alumnus[id] = true;
    }

    cin >> m;
    vector<string> guests(m);
    for (int i = 0; i < m; i++)
    {
        cin >> guests[i];
        if (alumnus[guests[i]])
            cnt++;
    }

    cout << cnt << endl;
    if (cnt > 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (stoi(guests[i].substr(6, 8)) < birthday && alumnus[guests[i]] == true)
            {
                birthday = stoi(guests[i].substr(6, 8));
                oldestAlumnu = guests[i];
            }
        }
        cout << oldestAlumnu << endl;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (stoi(guests[i].substr(6, 8)) < birthday)
            {
                birthday = stoi(guests[i].substr(6, 8));
                oldestGuest = guests[i];
            }
        }
        cout << oldestGuest << endl;
    }
    return 0;
}