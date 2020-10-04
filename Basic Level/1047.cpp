#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int group[1005] = {0};
	int group_num, member, grade, index, max_grade = 0;
	while (n--)
	{
		scanf("%d-%d %d", &group_num, &member, &grade);
		group[group_num] += grade;
	}

	for (int i = 1; i <= 1000; i++)
	{
		if (max_grade < group[i])
		{
			max_grade = group[i];
			index = i;
		}
	}
	printf("%d %d\n", index, max_grade);
	return 0;
}