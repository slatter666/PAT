#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, maxleft = 0;
	cin >> n;
	vector<int> arr(n), temp(n), rec;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		temp[i] = arr[i];
	}

	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; i++)
	{
		if (temp[i] == arr[i] && arr[i] > maxleft) // 当前元素处于正确位置并且该值大于所有左边元素的值
			rec.push_back(arr[i]);
		if (arr[i] > maxleft)
			maxleft = arr[i];
	}

	cout << rec.size() << endl;
	if (rec.size() != 0)
	{
		for (int i = 0; i < rec.size(); i++) // 不需要专门去sort进行rec的升序操作，因为本来就是按照顺序push到rec数组中的
		{
			if (i != 0)
				cout << " ";
			cout << rec[i];
		}
	}
	cout << endl; // 不知道为啥，反正就是要加这一句测试点二格式错误才给过，好像是说应该输出两行，即便第二行没有元素也要有一行，这真是。。。
	return 0;
}