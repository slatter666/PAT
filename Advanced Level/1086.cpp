#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> pre, in, post;

void postorder(int left, int right, int root)
{
    if (left > right)
        return;
    int i = left;
    while (i < right && in[i] != pre[root])
        i++;
    postorder(left, i - 1, root + 1);
    postorder(i + 1, right, root + 1 + i - left); // 左子树有i-left个节点，那么右子树就是从root+i-left+1开始
    post.push_back(in[i]);
}

int main()
{
    string str;
    int n, num;
    stack<int> s;
    cin >> n;
    while (cin >> str)
    {
        if (str == "Push")
        {
            cin >> num;
            pre.push_back(num);
            s.push(num);
        }
        else
        {
            in.push_back(s.top());
            s.pop();
        }
    }

    postorder(0, n - 1, 0);
    for (int i = 0; i < n; i++)
    {
        cout << post[i];
        if (i != n - 1)
            cout << " ";
    }
    return 0;
}