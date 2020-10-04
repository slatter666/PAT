#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m, k, num, sum_stu = 0, sum_obj = 0;
    string name;
    set<int> obj;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        obj.insert(num);
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        cin >> name >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> num;
            if (obj.find(num) != obj.end())
            {
                if (flag)
                {
                    cout << name << ":";
                    flag = false;
                }
                printf(" %.04d", num); //此处有坑,需要格式化输出四位数,不足四位补前导0
                sum_obj++;
            }
        }
        if (!flag)
        {
            sum_stu++;
            cout << endl;
        }
    }
    cout << sum_stu << " " << sum_obj << endl;
    return 0;
}