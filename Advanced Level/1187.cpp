#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int key, prior;
    node *left, *right;
} tree[35];

bool cmp(node n1, node n2)
{
    return n1.prior < n2.prior;
}

node *insert(node *root, node cur)
{
    if (root == NULL)
    {
        root = new node();
        root->key = cur.key;
        root->prior = cur.prior;
        root->left = root->right = NULL;
    }
    else
    {
        if (cur.key < root->key)
            root->left = insert(root->left, cur);
        else if (cur.key > root->key)
            root->right = insert(root->right, cur);
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tree[i].key >> tree[i].prior;
    sort(tree, tree + n, cmp);

    node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, tree[i]);

    vector<int> keyLevel, priorLevel;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        keyLevel.push_back(front->key);
        priorLevel.push_back(front->prior);
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
    }

    for (int i = 0; i < keyLevel.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << keyLevel[i];
    }
    cout << endl;
    for (int i = 0; i < priorLevel.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << priorLevel[i];
    }
    cout << endl;
    return 0;
}