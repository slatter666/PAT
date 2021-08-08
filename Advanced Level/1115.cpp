#include <iostream>
using namespace std;

int maxLevel = -1, cnt1 = 0, cnt2 = 0; // cnt1记录最底层结点数目, cnt2记录次底层结点数目
struct node
{
    int value;
    int level;
    node *left;
    node *right;
};

node *insert(node *root, int x, int level)
{
    if (level > maxLevel)
        maxLevel = level;

    if (root == NULL)
    {
        root = new node();
        root->level = level;
        root->value = x;
        root->left = root->right = NULL;
    }
    else
    {
        if (x <= root->value) // 比根节点值小
            root->left = insert(root->left, x, root->level + 1);
        else //比根节点值大
            root->right = insert(root->right, x, root->level + 1);
    }
    return root;
}

void dfs(node *root)
{
    if (root->level == maxLevel)
        cnt1++;
    else if (root->level == maxLevel - 1)
        cnt2++;

    if (root->left != NULL)
        dfs(root->left);
    if (root->right != NULL)
        dfs(root->right);
}

int main()
{
    int n, num;
    node *root = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        root = insert(root, num, 0);
    }

    dfs(root);
    cout << cnt1 << " + " << cnt2 << " = " << cnt1 + cnt2 << endl;
    return 0;
}