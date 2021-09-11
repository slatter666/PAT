#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> state(110);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> state[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int cnt = 0;
            vector<int> temp = state;
            temp[i] = -temp[i], temp[j] = -temp[j];
            vector<int> visit(110, 1);
            visit[i] = visit[j] = -1;
            for (int k = 1; k <= n; k++)
            {
                if (temp[k] * visit[abs(temp[k])] < 0)
                    cnt++;
                if (cnt > 2)
                    break;
            }
            if (cnt == 2)
            {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}