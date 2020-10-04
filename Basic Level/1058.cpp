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
    int wrongCnt[m] = {0};
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
        int score = 0;
        getchar();
        for (int j = 0; j < m; j++)
        {
            if (j != 0)
                scanf(" ");

            set<char> t;
            scanf("(%d", &k);
            for (int v = 0; v < k; v++)
            {
                scanf(" %c", &c);
                t.insert(c);
            }

            scanf(")");
            if (pro[j].s == t)
                score += pro[j].point;
            else
                wrongCnt[j]++;
        }
        printf("%d\n", score);
    }

    int maxWrongCnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (wrongCnt[i] > maxWrongCnt)
            maxWrongCnt = wrongCnt[i];
    }

    if (maxWrongCnt == 0)
        printf("Too simple");
    else
    {
        printf("%d", maxWrongCnt);
        for (int i = 0; i < m; i++)
        {
            if (wrongCnt[i] == maxWrongCnt)
                printf(" %d", i + 1);
        }
    }
    return 0;
}