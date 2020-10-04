#include <iostream>
#include <cmath>
using namespace std;

struct item{
	int coe;      //系数
	int exp;      //指数
	int der_coe;          //求导后的系数
	int der_exp;          //求导后的指数
};

int main()
{
	item nape[105];
	bool flag = false;
	int count = 0;
	while(cin>>nape[count].coe>>nape[count].exp)
	{
		nape[count].der_coe = nape[count].coe * nape[count].exp;
		nape[count].der_exp = nape[count].exp - 1;
		if(nape[count].coe == 0 && nape[count].exp == 0)
			flag = true;
		if(nape[count].exp == 0 && count == 0)
			flag = true;
		if(nape[count].der_exp >= 0)
			count++;
	}

	if(flag)
		cout<<0<<" "<<0<<endl;
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout<<nape[i].der_coe<<" "<<nape[i].der_exp;
			if(i!=count-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}