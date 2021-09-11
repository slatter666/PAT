#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int value;
    node *left, *right;
};

bool full = true;
int n, m;
int post[35], in[35];
int level[1005], lchild[1005], rchild[1005], parent[1005];

node *create(int inLeft, int inRight, int postLeft, int postRight)
{
    if (inLeft > inRight)
        return NULL;
    int rootVal = post[postRight];
    int pos = inLeft;
    while (pos <= inRight && in[pos] != rootVal)
        pos++;
    node *temp = new node();
    temp->value = rootVal;
    temp->right = create(pos + 1, inRight, postRight - (inRight - pos), postRight - 1);
    temp->left = create(inLeft, pos - 1, postLeft, postRight - (inRight - pos) - 1);
    return temp;
}

void dfs(node *root, int depth)
{
    level[root->value] = depth;
    if (root->left != NULL)
    {
        lchild[root->value] = root->left->value;
        parent[root->left->value] = root->value;
        dfs(root->left, depth + 1);
    }
    if (root->right != NULL)
    {
        rchild[root->value] = root->right->value;
        parent[root->right->value] = root->value;
        dfs(root->right, depth + 1);
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        full = false;
}

vector<string> split(string s)
{
    vector<string> result;
    int index = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            result.push_back(s.substr(index, cnt));
            index = i + 1;
            cnt = 0;
        }
        else
            cnt++;
    }
    result.push_back(s.substr(index, cnt));
    return result;
}

int input(vector<string> &sentence)
{
    int result;
    string str;
    getline(cin, str);
    sentence = split(str);
    if (sentence[1] == "is")
    {
        if (sentence[0] == "It")
            result = 7;
        else if (sentence[3] == "parent")
            result = 3;
        else if (sentence[3] == "root")
            result = 1;
        else if (sentence[3] == "left")
            result = 4;
        else if (sentence[3] == "right")
            result = 5;
    }
    else if (sentence[1] == "and")
    {
        if (sentence[4] == "siblings")
            result = 2;
        else if (sentence[4] == "on")
            result = 6;
    }
    return result;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> post[i];
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    node *root = create(1, n, 1, n); // 根在第一层
    dfs(root, 1);

    cin >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        vector<string> sentence;
        int sort = input(sentence);
        if (sort == 1)
        {
            if (stoi(sentence[0]) == root->value)
                flag = true;
        }
        else if (sort == 2)
        {
            int num1 = stoi(sentence[0]), num2 = stoi(sentence[2]);
            if (parent[num1] == parent[num2])
                flag = true;
        }
        else if (sort == 3)
        {
            int num1 = stoi(sentence[0]), num2 = stoi(sentence[5]);
            if (num1 == parent[num2])
                flag = true;
        }
        else if (sort == 4)
        {
            int num1 = stoi(sentence[0]), num2 = stoi(sentence[6]);
            if (num1 == lchild[num2])
                flag = true;
        }
        else if (sort == 5)
        {
            int num1 = stoi(sentence[0]), num2 = stoi(sentence[6]);
            if (num1 == rchild[num2])
                flag = true;
        }
        else if (sort == 6)
        {
            int num1 = stoi(sentence[0]), num2 = stoi(sentence[2]);
            if (level[num1] == level[num2])
                flag = true;
        }
        else if (sort == 7)
        {
            if (full)
                flag = true;
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}