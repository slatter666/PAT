#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxS = -1, minDiff = 0x3f3f3f3f;
vector<int> arr;

void dfs()
{
    bool flag = false;
    sort(arr.begin(), arr.end());
    vector<int> temp = arr; // 备份arr
    int maxLoad = arr[arr.size() - 1];
    for (int i = 1; i <= maxLoad / 2; i++) // 每次都拆解最大的负载（否则会不满足第三个条件）
    {
        int load1 = i, load2; // load1、load2分别表示表示按照i、maxLoad-i拆解后的所有负载中的最小的负载、最大的负载
        // 其中数组中任何一个元素都是大于等于maxLoad/2的（条件要求了的），那么拆分之后i就是最小的，因此load1=i，load2就要看拆分后谁最大了
        if (arr.size() >= 2)
            load2 = max(maxLoad - i, arr[arr.size() - 2]);
        else
            load2 = maxLoad - i;

        if (load1 * 2 > load2) // 符合条件则可以继续dfs进行拆分
        {
            flag = true;
            arr.pop_back();
            arr.push_back(i);
            arr.push_back(maxLoad - i);
            dfs();
            arr = temp; // dfs返回之后恢复arr原本的数据
        }
    }

    if (flag == false) // 拆解到底了，就看谁分的更多，分的同样多就看谁分出来最大最小负载之差最小
    {
        int size = arr.size();
        if (size > maxS)
        {
            maxS = size;
            minDiff = arr.back() - arr.front();
        }
        else if (size == maxS)
            minDiff = min(minDiff, arr.back() - arr.front());
    }
}

int main()
{
    int s;
    cin >> s;
    arr.push_back(s);
    dfs();
    cout << maxS << " " << minDiff << endl;
    return 0;
}