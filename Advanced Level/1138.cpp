#include <iostream>
#include <vector>
using namespace std;

int n, pos;
int pre[50005], in[50005];
vector<int> post;

void getPost(int left, int right, int root)
{
    if (left > right)
        return;
    int index = left;
    while (index < right && in[index] != pre[root])
        index++;
    getPost(left, index - 1, root + 1);
    getPost(index + 1, right, index - left + root + 1);
    post.push_back(pre[root]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    getPost(0, n - 1, 0);
    cout << post[0] << endl;
    return 0;
}