#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, d, num, count;
    double e, use, pos = 0, sure = 0; //低电量阈值, 使用量, 可能空置,空置
    cin >> n >> e >> d;
    for (int j = 0; j < n; j++)
    {
        count = 0;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> use;
            if (use < e)
                count++;
        }

        if (count > num / 2)
        {
            if (num > d)
                sure++;
            else
                pos++;
        }
    }

    pos = pos * 100 / n;
    sure = sure * 100 / n;
    cout << setiosflags(ios::fixed) << setprecision(1) << pos << "% " << setprecision(1) << sure << "%" << endl;
    return 0;
}