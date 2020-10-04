#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int num, move;
    cin >> num >> move;
    int array[105];
    memset(array, 0, sizeof(array));
    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    move = num - move % num;
    for (int i = 0; i < num; i++)
    {
        cout << array[(i + move) % num];
        if (i != num - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}