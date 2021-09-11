#include <iostream>
using namespace std;

int main()
{
    char rec[3] = {'W', 'T', 'L'};
    char choose[3];
    double odd, max_odd, result = 0.65;
    for (int i = 0; i < 3; i++)
    {
        max_odd = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> odd;
            if (odd > max_odd)
            {
                max_odd = odd;
                choose[i] = rec[j];
            }
        }
        result *= max_odd;
    }

    result = (result - 1) * 2;
    for (int i = 0; i < 3; i++)
        printf("%c ", choose[i]);
    printf("%.2lf", result);
    return 0;
}