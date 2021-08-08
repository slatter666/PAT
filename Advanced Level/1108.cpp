#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        for (int i = 0; i < strlen(a); i++)
            if (a[i] != b[i])
                flag = false;

        if (!flag || temp > 1000 || temp < -1000)
            printf("ERROR: %s is not a legal number\n", a);
        else
        {
            result += temp;
            cnt++;
        }
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1)
        printf("The average of 1 number is %.2lf\n", result);
    else
        printf("The average of %d numbers is %.2lf\n", cnt, result / cnt);
    return 0;
}