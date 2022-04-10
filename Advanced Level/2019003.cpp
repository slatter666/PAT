#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};

node *insert(node *root, int num)
{
    if (root == NULL)
    {
        root = new node();
        root->val = num;
        root->left = root->right = NULL;
    }
    if (num < root->val)
        root->left = insert(root->left, num);
    else if (num > root->val)
        root->right = insert(root->right, num);

    return root;
}

int dfsCheck(node *root, bool &flag)
{
    int leftHeight = 0, rightHeight = 0;
    if (root->left != NULL)
        leftHeight = dfsCheck(root->left, flag);
    if (root->right != NULL)
        rightHeight = dfsCheck(root->right, flag);
    if (abs(leftHeight - rightHeight) > 1)
        flag = false;
    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    int k, n, num;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        node *root = NULL;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            root = insert(root, num);
        }
        int temp = dfsCheck(root, flag);
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}