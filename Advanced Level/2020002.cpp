#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int i = 0, j = 0, k = 0, n1, n2, n3, dist = 0x3f3f3f3f;

int main()
{
    int A, B, C;
    cin >> n1 >> n2 >> n3;
    vector<int> s1(n1), s2(n2), s3(n3);
    for (int s = 0; s < n1; s++)
        cin >> s1[s];
    for (int s = 0; s < n2; s++)
        cin >> s2[s];
    for (int s = 0; s < n3; s++)
        cin >> s3[s];

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());

    while (i < n1 && j < n2 && k < n3)
    {

        int a = s1[i], b = s2[j], c = s3[k];
        int temp = abs(a - b) + abs(a - c) + abs(b - c);
        if (temp <= dist) // 要求输出最大的三元组，因此这里需要加上等号，因为越往后遍历肯定是越大的
        {
            dist = temp;
            A = a, B = b, C = c;
        }

        if (a <= b && a <= c) // 没办法，它要最大三元组，所以应当所有序列全部遍历完，而不是一个遍历完就算了
        {
            if (i != n1 - 1)
                i++;
            else
            {
                if (b <= c)
                {
                    if (j != n2 - 1)
                        j++;
                    else
                        k++;
                }
                else if (c <= b)
                {
                    if (k != n3 - 1)
                        k++;
                    else
                        j++;
                }
            }
        }
        else if (b <= a && b <= c)
        {
            if (j != n2 - 1)
                j++;
            else
            {
                if (a <= c)
                {
                    if (i != n1 - 1)
                        i++;
                    else
                        k++;
                }
                else if (c <= a)
                {
                    if (k != n3 - 1)
                        k++;
                    else
                        i++;
                }
            }
        }
        else if (c <= a && c <= b)
        {
            if (k != n3 - 1)
                k++;
            else
            {
                if (a <= b)
                {
                    if (i != n1 - 1)
                        i++;
                    else
                        j++;
                }
                else if (b <= a)
                {
                    if (j != n2 - 1)
                        j++;
                    else
                        i++;
                }
            }
        }
    }
    printf("MinD(%d, %d, %d) = %d\n", A, B, C, dist);
    return 0;
}