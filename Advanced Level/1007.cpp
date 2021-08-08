#include <iostream>
using namespace std;

int main()
{
    int k, tfirst, first = 0, last = 0, max_sum, temp = 0;
    cin >> k;
    int arr[k];
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        temp += arr[i];
        if (i == 0)
            max_sum = temp;
        if (temp < arr[i]) //加上该数之后比该数更小了,说明temp是负数
        {
            temp = arr[i];
            tfirst = i;
        }
        if (temp > max_sum)
        {
            max_sum = temp;
            first = tfirst;
            last = i;
        }
    }

    if (max_sum < 0)
        cout << 0 << " " << arr[0] << " " << arr[k - 1] << endl;
    else
        cout << max_sum << " " << arr[first] << " " << arr[last] << endl;
    return 0;
}