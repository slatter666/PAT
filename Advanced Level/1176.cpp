#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, dif = 0x3f3f3f3f;
    cin >> n;
    vector<int> rec;
    rec.push_back(1);
    rec.push_back(1);
    int temp = 1;
    while (true)
    {
        if (abs(n - temp) < dif)
            dif = abs(n - temp);
        else
        {
            cout << rec[rec.size() - 2] << endl;
            break;
        }

        temp = rec[rec.size() - 1] + rec[rec.size() - 2];
        rec.push_back(temp);
    }

    return 0;
}