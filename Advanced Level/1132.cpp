#include <iostream>
using namespace std;

int main()
{
    int n;
    string num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int k = num.size();
        int a = stoi(num.substr(0, k / 2));
        int b = stoi(num.substr(k / 2));
        if (a * b != 0 && stoi(num) % (a * b) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}