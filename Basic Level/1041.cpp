#include <iostream>
using namespace std;

struct message
{
	string id;
	int exam;
} stu[1005];

int main()
{
	int n, measure, seat;
	string number;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number >> measure >> seat;
		stu[measure].id = number;
		stu[measure].exam = seat;
	}

	int m, wait;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> wait;
		cout << stu[wait].id << " " << stu[wait].exam << endl;
	}
	return 0;
}