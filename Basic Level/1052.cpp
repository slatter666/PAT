#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> v(3);

int main()
{
	string str;
	int index;
	for (int j = 0; j < 3; j++)
	{
		getline(cin, str);
		int b = 0, e = 0;
		while (b < str.size())
		{
			if (str[b] == '[')
			{
				while (e++ < str.size())
				{
					if (str[e] == ']')
					{
						v[j].push_back(str.substr(b + 1, e - b - 1));
						break;
					}
				}
			}
			b++;
		}
	}

	int n, left_hand, left_eye, mouth, right_eye, right_hand;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> left_hand >> left_eye >> mouth >> right_eye >> right_hand;
		if (left_hand > v[0].size() || right_hand > v[0].size() || left_eye > v[1].size() || right_eye > v[1].size() || mouth > v[2].size() || left_hand < 1 || left_eye < 1 || mouth < 1 || right_hand < 1 || right_eye < 1)
			cout << "Are you kidding me? @\\/@" << endl;
		else
			cout << v[0][left_hand - 1] << "(" << v[1][left_eye - 1] << v[2][mouth - 1] << v[1][right_eye - 1] << ")" << v[0][right_hand - 1] << endl;
	}
}