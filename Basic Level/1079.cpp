#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
	int left = 0, right = s.size() - 1;
	bool flag = true;
	if (s[right] == '0' && s.size() > 1)
		flag = false;
	else
	{
		while (left < right)
		{
			if (s[left] != s[right])
			{
				flag = false;
				break;
			}
			left++;
			right--;
		}
	}
	return flag;
}

string add(string s1, string s2)
{
	string rec = "";
	int carry = 0, sum = 0;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		sum = carry + s1[i] - '0' + s2[i] - '0';
		carry = sum / 10;
		rec.insert(0, to_string(sum % 10));
	}
	if (carry)
		rec.insert(0, to_string(carry));
	return rec;
}

int main()
{
	string result;
	int count = 0;
	cin >> result;
	while (true)
	{
		if (isPalindrome(result))
		{
			cout << result << " is a palindromic number." << endl;
			break;
		}

		if (count == 10)
		{
			cout << "Not found in 10 iterations." << endl;
			break;
		}
		else
		{
			string s = result;
			reverse(s.begin(), s.end());
			cout << result << " + " << s << " = " << add(result, s) << endl;
			result = add(result, s);
		}
		count++;
	}
}