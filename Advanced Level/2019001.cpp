#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    int n;
    string num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        set<int> rec;
        rec.insert(stoi(num)); // 需要注意这里也要把初始数字插入进去，因为循环有可能会回到初始数据
        bool flag = true;
        int cnt = 0;
        while (true)
        {
            if (num == "1")
                break;
            int temp = 0;
            for (int j = 0; j < num.size(); j++)
            {
                temp += pow(num[j] - '0', 2);
            }
            cnt++;
            if (rec.find(temp) == rec.end())
            {
                rec.insert(temp);
                num = to_string(temp);
            }
            else
            {
                cout << temp << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << cnt << endl;
    }
    return 0;
}