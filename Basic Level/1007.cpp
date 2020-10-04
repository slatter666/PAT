#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 3)
    {
        return num > 1;
    }
    else if (num % 6 != 1 && num % 6 != 5)
        return false;

    int sq = sqrt(num);
    for (int i = 5; i <= sq; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
	int num;
	int count = 0;
	cin>>num;
	for (int i = 3; i <= num-2; i++)
	{
		if(isPrime(i) && isPrime(i+2))
		{
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}