#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int val, height, tag;
    node *left;
    node *right;
};

int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

node *rotateLeft(node *root) // 左旋
{
    // 这样写也是可以的，不过注意更新height的顺序一定是从下至上的，根结点的高度最后更新
    // node *temp = root;
    // root = root->right;
    // temp->right = root->left;
    // root->left = temp;
    // temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1; // 这样的话就需要先更新temp的高度再更新root的高度
    // root->height = max(getHeight(root->left), getHeight(root->right)) + 1; // 最后一定是更新整棵树根节点的高度，从下至上
    // return root;

    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

node *rotateRight(node *root) // 右旋
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}

node *rotateLeftRight(node *root) // 左右旋
{
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node *rotateRightLeft(node *root) // 右左旋
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
        root->height = 1;
    }
    else if (val < root->val) // 插入左子树
    {
        root->left = insert(root->left, val);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            if (val < root->left->val) // 左左 右旋
                root = rotateRight(root);
            else // 左右 左右旋
                root = rotateLeftRight(root);
        }
    }
    else // 插入右子树
    {
        root->right = insert(root->right, val);
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        if (getHeight(root->right) - getHeight(root->left) == 2)
        {
            if (val > root->right->val) // 右右    左旋
                root = rotateLeft(root);
            else // 右左 右左旋
                root = rotateRightLeft(root);
        }
    }
    return root;
}

int maxTag = 0; // 给每个结点设置标签，用于校验是否为完全二叉树
vector<int> levelOrder(node *root)
{
    vector<int> res;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        maxTag = temp->tag; // 因为是层序遍历，所以tag肯定是越来越大的，所以不需要用max函数
        q.pop();
        res.push_back(temp->val);
        if (temp->left != NULL)
        {
            temp->left->tag = temp->tag * 2;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            temp->right->tag = temp->tag * 2 + 1;
            q.push(temp->right);
        }
    }
    return res;
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

    root->tag = 1;
    vector<int> rec = levelOrder(root);
    for (int i = 0; i < rec.size(); i++)
    {

        if (i != 0)
            cout << " ";
        cout << rec[i];
    }
    cout << endl;
    if (n == maxTag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}