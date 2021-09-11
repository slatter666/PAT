#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int templen, maxlen = 1;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            templen = j - i + 1;
            if (templen > maxlen) // 大于才比较，不大于没必要去比较
            {
                int left = i, right = j;
                while (str[left] == str[right] && left <= right) // 我发现这玩意儿写得比调用reverse()函数再进行比较还快
                {
                    left++;
                    right--;
                }
                if (right < left)
                    maxlen = templen;
            }
        }
    }
    cout << maxlen << endl;
    return 0;
}

// while循环之前写法是下面这样的，测试点4和6会错，因为这样即使当前str[left]不等于str[right]了，依然会进行++和--操作，那么abca就会被判定为合法的
// while(str[left++] == str[right--] && left <= right)