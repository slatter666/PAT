#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k, num;
    int deque[100005]; // 模拟双端队列
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        q.push(num);
    }

    while (k--)
    {
        bool flag = true;
        int front = 1, rear = 0;
        queue<int> temp = q;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            while (!temp.empty()) // 这里temp写成q了，死循环不报错找了半天
            {
                if (deque[front] == num || deque[rear] == num) // 有可能前面的队列可以出元素符合序列
                    break;
                else // 两边都不满足，那么往双端队列里面插入数据
                {
                    int t = temp.front();
                    temp.pop();
                    deque[++rear] = t;
                    if (deque[rear] == num) // 既然前面出不了，只能后面有可能会出元素了
                        break;
                }
            }
            if (deque[front] == num)
                front++;
            else if (deque[rear] == num)
                rear--;
            else
                flag = false; // 不能break，因为必须把元素输入完毕
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

// 两端进一端出，输出受限的双端队列实现
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// int main()
// {
//     int n, k, num;
//     cin >> n >> k;
//     vector<int> rec(10005), temp(10005), deque; // 模拟双端队列,允许两端进一端出
//     for (int i = 0; i < n; i++)
//         cin >> rec[i];

//     while (k--)
//     {
//         int indexRec = 0, indexTemp = 0;
//         deque.clear();
//         map<int, int> pos;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> temp[i];
//             pos[temp[i]] = i; // 记录位置
//         }

//         while (indexRec < n)
//         {
//             if (deque.empty()) // 空的时候就直接往里面插元素就好了
//                 deque.push_back(rec[indexRec++]);
//             else
//             {
//                 int curFront = pos[deque[0]];  // 队头在检查序列中的下标
//                 int next = pos[rec[indexRec]]; // 新元素在检查序列中的下标
//                 if (next < curFront)
//                     deque.insert(deque.begin(), rec[indexRec++]); // 输出序列中在队头左边就放左边
//                 else
//                     deque.push_back(rec[indexRec++]); // 输出序列中在队头右边就放右边
//             }

//             while (deque.front() == temp[indexTemp])
//             {
//                 indexTemp++;
//                 deque.erase(deque.begin());
//             }
//         }

//         if (indexTemp == n)
//             cout << "yes" << endl;
//         else
//             cout << "no" << endl;
//     }
//     return 0;
// }