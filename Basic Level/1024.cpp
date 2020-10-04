#include <stdio.h>
using namespace std;

int main()
{
    char sign;             //底数符号
    char num[10005] = {0}; //底数
    int exp;               //指数
    scanf("%c%c.%[0-9]E%d", &sign, &num[0], num + 1, &exp);
    if (sign == '-')
        printf("-");
    if (exp < 0)
    {
        printf("0.");
        for (int i = 0; i < -exp - 1; i++)
        {
            printf("0");
        }
        printf("%s", num);
    }
    else
    {
        for (int i = 0; i <= exp || num[i] != '\0'; i++)
        {
            if (i == exp + 1)
                printf(".");
            printf("%c", num[i] == '\0' ? '0' : num[i]);
        }
    }
    return 0;
}