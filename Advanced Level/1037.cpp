#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int nc, np, cnt1 = 0, cnt2 = 0, result = 0;
    cin >> nc;
    vector<int> coupon(nc);
    for (int i = 0; i < nc; i++)
        cin >> coupon[i];

    cin >> np;
    vector<int> product(np);
    for (int i = 0; i < np; i++)
        cin >> product[i];

    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());
    while (cnt1 < nc && cnt2 < np && coupon[cnt1] < 0 && product[cnt2] < 0)
    {
        result += coupon[cnt1] * product[cnt2];
        cnt1++;
        cnt2++;
    }
    cnt1 = nc - 1;
    cnt2 = np - 1;
    while (cnt1 >= 0 && cnt2 >= 0 && coupon[cnt1] > 0 && product[cnt2] > 0)
    {
        result += coupon[cnt1] * product[cnt2];
        cnt1--;
        cnt2--;
    }
    cout << result << endl;
    return 0;
}