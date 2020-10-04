#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int hundred = num / 100;       //百位
    int decade = (num % 100) / 10; //十位
    int unit = (num % 10);         //个位

    while (hundred--)
    {
        cout << "B";
    }

    while (decade--)
    {
        cout << "S";
    }

    for (int i = 1; i <= unit; i++)
    {
        cout << i;
    }

    cout << endl;
    return 0;
}