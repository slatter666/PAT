#include <iostream>
using namespace std;

struct game
{
    int han;
    int hua;
    int he = 0;
};

int main()
{
    int n;
    cin >> n;
    game first, second; //甲、乙
    while (n--)
    {
        cin >> first.han >> first.hua >> second.han >> second.hua;
        if (first.hua == second.hua)
        {
            continue;
        }
        else
        {
            if (first.han + second.han == first.hua)
            {
                second.he++;
            }
            else if (first.han + second.han == second.hua)
            {
                first.he++;
            }
        }
    }
    cout << first.he << " " << second.he << endl;
    return 0;
}