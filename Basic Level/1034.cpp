#include <iostream>
#include <cmath>
using namespace std;

long long int gcd(long long int x, long long int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

void simplify(long long int a, long long int b)
{
    long long int x, y, comm, inte, element, temp;
    if (b == 0)
    {
        printf("Inf");
        return;
    }
    comm = gcd(abs(a), b); //求最大公约数,因为'-'只会出现在分子前面
    a /= comm;
    b /= comm;
    inte = abs(a) / b;           //整数部分
    element = abs(a) - inte * b; //分子部分

    if (a < 0)
    {
        if ((inte != 0) && (element != 0))
            printf("(-%lld %lld/%lld)", inte, element, b);
        else if ((inte != 0) && (element == 0))
            printf("(-%lld)", inte);
        else if ((inte == 0) && (element != 0))
            printf("(-%lld/%lld)", element, b);
        else
            printf("0");
    }
    else
    {
        if ((inte != 0) && (element != 0))
            printf("%lld %lld/%lld", inte, element, b);
        else if ((inte != 0) && (element == 0))
            printf("%lld", inte);
        else if ((inte == 0) && (element != 0))
            printf("%lld/%lld", element, b);
        else
            printf("0");
    }
}

int main()
{
    long long int a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    char op[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
    {
        simplify(a1, b1);
        printf(" %c ", op[i]);
        simplify(a2, b2);
        printf(" = ");
        switch (op[i])
        {
        case '+':
            simplify(a1 * b2 + a2 * b1, b1 * b2);
            break;

        case '-':
            simplify(a1 * b2 - a2 * b1, b1 * b2);
            break;

        case '*':
            simplify(a1 * a2, b1 * b2);
            break;

        case '/':
            if(a2<0)
                simplify(a1 * b2 * (-1), abs(a2) * b1);
            else
                simplify(a1 * b2, abs(a2) * b1);
            break;

        default:
            break;
        }
        printf("\n");
    }
    return 0;
}