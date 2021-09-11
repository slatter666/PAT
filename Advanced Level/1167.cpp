#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

int n, cnt;
int sequence[35];

int find(int left, int right)
{
    int minIndex = left, minValue = sequence[left];
    for (int i = left + 1; i <= right; i++)
    {
        if (sequence[i] < minValue)
        {
            minIndex = i;
            minValue = sequence[i];
        }
    }
    return minIndex;
}

node *create(int left, int right)
{
    if (left > right)
        return NULL;

    int cur = find(left, right);
    node *temp = new node();
    temp->data = sequence[cur];
    temp->left = create(left, cur - 1);
    temp->right = create(cur + 1, right);
    return temp;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> sequence[i];
    node *root = create(1, n);

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (cnt != 0)
            cout << " ";
        cout << front->data;

        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
        cnt++;
    }
    return 0;
}