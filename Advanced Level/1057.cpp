#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, num, mid;
vector<int> vec;
multiset<int> s1, s2;

void adjust()
{
    multiset<int>::iterator it;
    if (s1.size() < s2.size())
    {
        it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
    if (s1.size() > s2.size() + 1)
    {
        it = s1.end();
        it--;
        s2.insert(*it);
        s1.erase(it);
    }
    if (!s1.empty())
    {
        it = s1.end();
        it--;
        mid = *it;
    }
}

int main()
{
    cin >> n;
    string op;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == "Pop")
        {
            if (vec.size() == 0)
                cout << "Invalid" << endl;
            else
            {
                int back = vec.back();
                cout << vec.back() << endl;
                vec.pop_back();
                if (back <= mid)
                    s1.erase(s1.find(back));
                else
                    s2.erase(s2.find(back));
                adjust();
            }
        }
        else if (op == "Push")
        {
            cin >> num;
            vec.push_back(num);
            if (s1.empty())
                s1.insert(num);
            else if (num <= mid) // 不空的情况下小于mid值插入小set
                s1.insert(num);
            else
                s2.insert(num);
            adjust();
        }
        else
        {
            if (vec.size() == 0)
                cout << "Invalid" << endl;
            else
                cout << mid << endl;
        }
    }
    return 0;
}