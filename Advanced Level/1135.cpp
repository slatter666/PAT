#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};
vector<int> rec;

node *insert(node *root, int value)
{
    if (root == NULL)
    {
        root = new node();
        root->left = root->right = NULL;
        root->val = value;
    }
    else if (abs(value) < abs(root->val))
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

bool judge1(node *root)
{
    if (root == NULL)
        return true;
    if (root->val < 0)
    {
        if (root->left != NULL && root->left->val < 0)
            return false;
        if (root->right != NULL && root->right->val < 0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int getBlackNum(node *root)
{
    if (root == NULL)
        return 0;
    int l = getBlackNum(root->left);
    int r = getBlackNum(root->right);
    if (root->val > 0)
        return max(l, r) + 1;
    else
        return max(l, r);
}

bool judge2(node *root)
{
    if (root == NULL)
        return true;
    if (getBlackNum(root->left) != getBlackNum(root->right))
        return false;
    return judge2(root->left) && judge2(root->right);
}

int main()
{
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        rec.resize(n);
        node *root = NULL;
        for (int j = 0; j < n; j++)
        {
            cin >> rec[j];
            root = insert(root, rec[j]);
        }
        if (rec[0] > 0 && judge1(root) && judge2(root))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}