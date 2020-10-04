#include <iostream>
#include <set>
using namespace std;

struct question
{
    int point;
    int choose;
    int right;
    set<char> s;
} pro[105];

int main()
{
    int n, m, k;
    char c;
    scanf("%d %d", &n, &m);
    int wrongCnt[m][5] = {0};
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &pro[i].point, &pro[i].choose, &pro[i].right);
        for (int j = 0; j < pro[i].right; j++)
        {
            scanf(" %c", &c);
            pro[i].s.insert(c);
        }
    }

    for (int i = 0; i < n; i++)
    {
        double score = 0;
        getchar();
        for (int j = 0; j < m; j++)
        {
            bool flag = true;
            if (j != 0)
                scanf(" ");

            set<char> t;
            scanf("(%d", &k);
            for (int v = 0; v < k; v++)
            {
                scanf(" %c", &c);
                if (pro[j].s.find(c) == pro[j].s.end()) //则该选项是错误选项
                {
                    flag = false;
                    wrongCnt[j][c - 'a']++;
                }
                t.insert(c);
            }

            scanf(")");
            for (char word : pro[j].s)
            {
                if (t.find(word) == t.end())
                    wrongCnt[j][word - 'a']++;
            }

            if (flag)
            {
                if (k == pro[j].right)
                    score += pro[j].point;
                else
                    score += pro[j].point * 1.0 / 2;
            }
        }
        printf("%.1lf\n", score);
    }

    int maxWrongCnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (wrongCnt[i][j] > maxWrongCnt)
                maxWrongCnt = wrongCnt[i][j];
        }
    }

    if (maxWrongCnt == 0)
        printf("Too simple");
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (wrongCnt[i][j] == maxWrongCnt)
                    printf("%d %d-%c\n", maxWrongCnt, i + 1, j + 'a');
            }
        }
    }
    return 0;
}