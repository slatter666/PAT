#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tea, stu, count = 0, max = 0, min = m;
        cin >> tea;
        double sum = 0;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> stu;
            if (stu >= 0 && stu <= m)
            {
                sum += stu;
                count++;
                if (max < stu)
                    max = stu;
                if (min > stu)
                    min = stu;
            }
        }
        sum = ((sum - min - max) / (count - 2) + tea) / 2 + 0.5;
        cout << (int)sum << endl;
    }
    return 0;
}