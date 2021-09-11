#include <iostream>
using namespace std;

int main()
{
    int minCnt = 0x3f3f3f3f;
    string str, seq, result;
    cin >> str >> seq;
    for (int i = 0; i <= str.size() - seq.size(); i++)
    {
        int j, cnt = 0;
        for (j = i; j < str.size(); j++)
        {
            if (str[j] == seq[cnt])
                cnt++;
            if (cnt == seq.size() || j - i + 1 >= minCnt) // 这里第二个判断如果字符串超级场的话会加速很多的，应该不会超时
                break;
        }
        if (cnt == seq.size() && j - i + 1 < minCnt)
        {
            minCnt = j - i + 1;
            result = str.substr(i, j - i + 1);
        }
    }
    cout << result << endl;
    return 0;
}