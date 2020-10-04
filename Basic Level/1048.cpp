#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

char list[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main()
{
	char s1[105], s2[105];
	memset(s1, '0', sizeof(s1));
	memset(s2, '0', sizeof(s2));
	scanf("%s %s", s1, s2);
	int len = max(strlen(s1), strlen(s2));
	strrev(s1);
	strrev(s2);
	s1[strlen(s1)] = '0';
	s2[strlen(s2)] = '0';

	stack<char> st;
	for (int i = 0; i < len; i++)
	{
		if (i % 2 == 0) //奇数位
			st.push(list[(s1[i] - '0' + s2[i] - '0') % 13]);
		else //偶数位
			st.push(s2[i] - s1[i] >= 0 ? s2[i] - s1[i] + '0' : s2[i] - s1[i] + '0' + 10);
	}

	while (!st.empty())
	{
		printf("%c", st.top());
		st.pop();
	}
	return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #include <stack>
// using namespace std;

// char list[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

// int main()
// {
//     char s1[105], s2[105];
//     memset(s1, '0', sizeof(s1));
//     memset(s2, '0', sizeof(s2));
//     scanf("%s %s", s1, s2);
//     int len = max(strlen(s1), strlen(s2));
//     reverse(s1, s1 + strlen(s1));
//     reverse(s2, s2 + strlen(s2));
//     s1[strlen(s1)] = '0';
//     s2[strlen(s2)] = '0';

//     stack<char> st;
//     for (int i = 0; i < len; i++)
//     {
//         if (i % 2 == 0) //奇数位
//             st.push(list[(s1[i] - '0' + s2[i] - '0') % 13]);
//         else //偶数位
//             st.push(s2[i] - s1[i] >= 0 ? s2[i] - s1[i] + '0' : s2[i] - s1[i] + '0' + 10);
//     }

//     while (!st.empty())
//     {
//         printf("%c", st.top());
//         st.pop();
//     }
//     return 0;
// }