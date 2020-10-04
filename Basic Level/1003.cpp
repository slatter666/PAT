#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    string str;
    cin >> num;
    while (num--)
    {
        cin >> str;
        int count1 = 0, count2 = 0, count3 = 0, index = 0;

        while (str[index] == 'A')
        {
            count1++;
            index++;
        }
        if (str[index++] == 'P')
        {
            while (str[index] == 'A')
            {
                count2++;
                index++;
            }
            if (str[index++] == 'T')
            {
                while (str[index] == 'A')
                {
                    count3++;
                    index++;
                }
            }
        }

        if (index == str.size() && count2 > 0 && count1 * count2 == count3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}