#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int rec[1005];
int n, used;
vector<int> post;

struct node
{
    int value;
    node *left;
    node *right;
};

node *makeBST(int cursor, int ceil, int floor)
{
    node *temp = new node;
    temp->value = rec[cursor];
    used++;

    int i;
    for (i = cursor + 1; rec[i] >= floor && rec[i] < rec[cursor] && i < n; i++) {}

    if (i == cursor + 1)
        temp->left = NULL;
    else
        temp->left = makeBST(cursor + 1, rec[cursor], floor);

    if (rec[i] >= rec[cursor] && rec[i] < ceil && i < n)
        temp->right = makeBST(i, ceil, rec[cursor]);
    else
        temp->right = NULL;
    return temp;
}

node *makeMBST(int cursor, int ceil, int floor)
{
    node *temp = new node;
    temp->value = rec[cursor];
    used++;

    int i;
    for (i = cursor + 1; rec[i] < ceil && rec[i] >= rec[cursor] && i < n; i++) {}

    if (i == cursor + 1)
        temp->left = NULL;
    else
        temp->left = makeMBST(cursor + 1, ceil, rec[cursor]);

    if (rec[i] < rec[cursor] && rec[i] >= floor && i < n)
        temp->right = makeMBST(i, rec[cursor], floor);
    else
        temp->right = NULL;
    return temp;
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->value);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rec[i];

    used = 0;
    node *root = makeBST(0, INF, -INF);
    if (used == n)
    {
        cout << "YES" << endl;
        postorder(root);
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << " ";
            cout << post[i];
        }
    }
    else
    {
        used = 0;
        root = makeMBST(0, INF, -INF);
        if (used == n)
        {
            cout << "YES" << endl;
            postorder(root);
            for (int i = 0; i < n; i++)
            {
                if (i != 0)
                    cout << " ";
                cout << post[i];
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}