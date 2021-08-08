#include <iostream>
#include <vector>
using namespace std;

struct account
{
	string username;
	string password;
};

int main()
{
	vector<account> vec;
	int n;
	string uname, pwd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> uname >> pwd;
		string stemp = "";
		for (int j = 0; j < pwd.size(); j++)
		{
			switch (pwd[j])
			{
			case '1':
				stemp.append("@");
				break;
			case '0':
				stemp.append("%");
				break;

			case 'l':
				stemp.append("L");
				break;
			case 'O':
				stemp.append("o");
				break;

			default:
				stemp.push_back(pwd[j]);
				break;
			}
		}
		if (pwd != stemp)
		{
			account user;
			user.username = uname;
			user.password = stemp;
			vec.push_back(user);
		}
	}
	if (vec.size() != 0)
	{
		cout << vec.size() << endl;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].username << " " << vec[i].password << endl;
		}
	}
	else
	{
		if (n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << n << " accounts and no account is modified" << endl;
	}
	return 0;
}