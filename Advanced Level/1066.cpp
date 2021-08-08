#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int val;
    int height;
    node *left;
    node *right;
};

int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

node *rotateLeft(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

node *rotateRight(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

node *rotateLeftRight(node *root)
{
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node *rotateRightLeft(node *root)
{
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node();
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
    }
    else if (val < root->val)
    {
        root->left = insert(root->left, val);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            if (val < root->left->val) // 左左
                root = rotateRight(root);
            else // 左右
                root = rotateLeftRight(root);
        }
    }
    else
    {
        root->right = insert(root->right, val);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        if (getHeight(root->left) - getHeight(root->right) == -2)
        {
            if (val > root->right->val) // 右右
                root = rotateLeft(root);
            else //右左
                root = rotateRightLeft(root);
        }
    }
    return root;
}

int main()
{
    int n, num;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        root = insert(root, num);
    }
    cout << root->val << endl;
    return 0;
}