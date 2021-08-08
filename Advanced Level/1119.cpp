#include <iostream>
#include <vector>
using namespace std;

bool unique = true;
int pre[35], post[35];
vector<int> in;

void getIn(int preLeft, int preRight, int postLeft, int postRight)
{
    if (preLeft == preRight) // 只有一个结点的情况（找到了最左边的点）        左 或 右
    {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) // 根结点
    {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight - 1]) // 找到右子树根节点的值在前序遍历中所在位置
            i++;
        if (i == preLeft + 1) // 如果preLeft+1和postRight-1一样就无法确定以该结点为根结点的子树是左子树还是右子树，属于不确定状态
            unique = false;
        else // 根结点是preLeft，i是右子树根结点，则pre左子树区间为(preLeft+1,i-1)，左子树有i-1-preLeft个结点，post左子树区间为(postLeft,postLeft+(i-1-preLeft)-1)因为包含自身所以减一
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        in.push_back(pre[preLeft]); //根
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];

    getIn(0, n - 1, 0, n - 1);
    if (unique)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = 0; i < in.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << in[i];
    }
    cout << endl;
    return 0;
}