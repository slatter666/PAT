#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int id = 0, rank, cnt = 0; // cnt表示完全正确的题数
    vector<int> score;
    int total = 0;
    bool isShow = false;
};

bool cmp(node n1, node n2)
{
    if (n1.total != n2.total)
        return n1.total > n2.total;
    else if (n1.cnt != n2.cnt)
        return n1.cnt > n2.cnt;
    else
        return n1.id < n2.id;
}

int main()
{
    int n, k, m, uid, pid, score; // count用于记录一共多少有过活动的学生
    cin >> n >> k >> m;
    vector<node> user(n + 1);
    vector<int> mark(k + 1);
    for (int i = 1; i <= n; i++)
        user[i].score.resize(k + 1, -1);

    for (int i = 1; i <= k; i++)
        cin >> mark[i];

    for (int i = 0; i < m; i++)
    {
        cin >> uid >> pid >> score;
        user[uid].id = uid;
        user[uid].score[pid] = max(user[uid].score[pid], score);
        if (score >= 0)
            user[uid].isShow = true;
        else if (user[uid].score[pid] == -1) // 这里不能用score==-1，否则之前提交有分数而之后提交没有过编译器此时会把之前的分数给改掉
            user[uid].score[pid] = -2;       // 表示改题提交过，因为最后输出如果没过编译器是输出0分而不是-
    }

    for (int i = 1; i <= n; i++)
    {
        if (user[i].id != 0)
        {
            for (int j = 1; j <= k; j++)
            {
                if (user[i].score[j] >= 0) //
                    user[i].total += user[i].score[j];
                if (user[i].score[j] == mark[j])
                    user[i].cnt++;
            }
        }
    }

    sort(user.begin() + 1, user.end(), cmp);
    for (int i = 1; i <= n; i++)
    {
        user[i].rank = i;
        if (user[i].total == user[i - 1].total && i != -1) // 不用判断i=1是因为题目保证了至少有一个学生有成绩
            user[i].rank = user[i - 1].rank;
    }

    for (int i = 1; i <= n; i++)
    {
        if (user[i].isShow == true) // 不能采用user[i].isShow == false判定，因为存在total=0且isShow==true的情况
        {
            printf("%d %05d %d", user[i].rank, user[i].id, user[i].total);
            for (int j = 1; j <= k; j++)
            {
                if (user[i].score[j] == -1)
                    printf(" -");
                else if (user[i].score[j] == -2)
                    printf(" 0");
                else
                    printf(" %d", user[i].score[j]);
            }
            printf("\n");
        }
    }
    return 0;
}

// 测试数据
// 2 1 2
// 20
// 00002 1 0
// 00001 1 -1
// 预期得到数据
// 1 00002 0 0