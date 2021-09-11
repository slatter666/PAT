#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int data, level;
    node *left, *right;
};

int n, curDepth;
int in[25], pre[25];

node *create(int inLeft, int inRight, int preLeft, int preRight, int depth)
{
    if (inLeft > inRight)
        return NULL;
    int value = pre[preLeft];
    node *temp = new node();
    temp->data = value;
    temp->level = depth;

    int index = inLeft;
    while (in[index] != value)
        index++;
    temp->left = create(inLeft, index - 1, preLeft + 1, preLeft + index - inLeft, depth + 1);
    temp->right = create(index + 1, inRight, preLeft + index - inLeft + 1, preRight, depth + 1);
    return temp;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++)
        cin >> pre[i];
    node *root = create(1, n, 1, n, 1);

    vector<int> result;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (curDepth < front->level)
        {
            result.push_back(front->data);
            curDepth++;
        }
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
    }
    for (int i = 0; i < result.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << result[i];
    }
    return 0;
}