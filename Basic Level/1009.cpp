#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<string> s;
	while(cin>>str)
	{
		s.push_back(str);
	}

	for (int i = s.size() - 1; i >= 0; i--)
	{
		cout<<s[i];
		if(i!=0)
			cout<<" ";
	}
	cout<<endl;
	return 0;
}