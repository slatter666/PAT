#include <iostream>
using namespace std;

int last, maxIndex = -1;

struct node
{
   int left;
   int right;
} tree[30];

void dfs(int root, int index)
{
   if (index > maxIndex)
   {
      maxIndex = index;
      last = root;
   }

   if (tree[root].left != -1)
      dfs(tree[root].left, index * 2);
   if (tree[root].right != -1)
      dfs(tree[root].right, index * 2 + 1);
}

int main()
{
   int n, root = 0;
   bool flag[30] = {0}; // 标记数组,最终为0的是根,因为给的全是孩子节点,因此没出现的结点一定是根
   string s1, s2;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> s1 >> s2;
      if (s1 == "-")
         tree[i].left = -1;
      else
      {
         tree[i].left = stoi(s1);
         flag[tree[i].left] = true;
      }

      if (s2 == "-")
         tree[i].right = -1;
      else
      {
         tree[i].right = stoi(s2);
         flag[tree[i].right] = true;
      }
   }

   while (flag[root])
      root++;

   dfs(root, 1);
   if (maxIndex == n)
      cout << "YES " << last << endl;
   else
      cout << "NO " << root << endl;
   return 0;
}