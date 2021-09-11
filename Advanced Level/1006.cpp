#include <iostream>
using namespace std;

int main()
{
	int n;
	string id, enter, leave, unlock, lock, begin = "24:00:00", end = "00:00:00";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> enter >> leave;
		if (enter < begin)
		{
			begin = enter;
			unlock = id;
		}
		if (leave > end)
		{
			end = leave;
			lock = id;
		}
	}
	cout << unlock << " " << lock << endl;
	return 0;
}

// 比较low的方法
// #include <iostream>
// using namespace std;

// struct time
// {
// 	int hour;
// 	int minute;
// 	int second;
// };

// bool compare(time t1, time t2)
// {
// 	if (t1.hour != t2.hour)
// 		return t1.hour > t2.hour;
// 	else if (t1.minute != t2.minute)
// 		return t1.minute > t2.minute;
// 	else
// 		return t1.second > t2.second;
// }

// int main()
// {
// 	int m;
// 	string id, first, last;
// 	time t1, t2, begin = {24, 0, 0}, end = {0, 0, 0}; //t1是学生进入时间,t2是学生离开时间
// 	cin >> m;
// 	for (int i = 0; i < m; i++)
// 	{
// 		cin >> id;
// 		scanf("%d:%d:%d %d:%d:%d", &t1.hour, &t1.minute, &t1.second, &t2.hour, &t2.minute, &t2.second);
// 		if (compare(begin, t1)) //如果进入的时间更早
// 		{
// 			first = id;
// 			begin = t1;
// 		}
// 		if (compare(t2, end)) //如果离开的时间更晚
// 		{
// 			last = id;
// 			end = t2;
// 		}
// 	}
// 	cout << first << " " << last << endl;
// 	return 0;
// }