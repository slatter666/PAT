#include <iostream>
using namespace std;

// 坑点在于含有正数前导零类似于00123.4（测试点四）   小数前导零类似于000.01234（测试点六）
string normalize(string s, int n)
{
    int cnt0 = 0;
    for (int i = 0; i < s.size(); i++) // 删除无用的前导0
    {
        if (s[i] == '0')
            cnt0++;
        else
            break;
    }
    if (s[cnt0] == '.')
        s = s.substr(cnt0 - 1);
    else
        s = s.substr(cnt0);

    string result;
    int count = 0;
    if (s[0] != '0') // 数字大于等于1
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '.')
                count++;
            else
            {
                s.erase(i, 1);
                break;
            }
        }
        s.insert(0, "0.");
        for (int i = 0; i < n; i++)
            s.append("0");
        s = s.substr(0, n + 2);
        result = s + "*10^" + to_string(count);
    }
    else //数字小于等于1
    {
        bool flag = false;                 // 防止0.0被转化为0.0*10^-1
        for (int i = 2; i < s.size(); i++) // 从小数点后第一位开始
        {
            if (s[i] == '0')
                count--;
            else
            {
                flag = true;
                s = s.substr(i);
                break;
            }
        }
        if (!flag)
        {
            count = 0;
            s = "";
        }
        s.insert(0, "0.");
        for (int i = 0; i < n; i++)
            s.append("0");
        s = s.substr(0, n + 2);

        result = s + "*10^" + to_string(count);
    }
    return result;
}

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    a = normalize(a, n);
    b = normalize(b, n);
    if (a == b)
        cout << "YES " << a << endl;
    else
        cout << "NO " << a << " " << b << endl;
    return 0;
}