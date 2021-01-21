#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int T;
int dp[2000010];
vector<int> prime;

void eratos()
{
	for(int i = 2; i <= 2000000; i++)
	{
		if(dp[i] == 1)
		{
			continue;
		}
		
		for(int j = i+i; j <= 2000000; j += i)
		{
			dp[j] = 1;
		}
	}
	
	for(int i = 2; i <= 2000000; i++)
	{
		if(dp[i] == 0)
		{
			prime.push_back(i);
		}
	}
}

int check(long long a)
{
	for(int i = 0; i < prime.size(); i++)
	{
		if(a % prime[i] == 0 && a / prime[i] == 1)
		{
			return 1;
		}
		else if(a % prime[i] == 0 && a / prime[i] != 1)
		{
			return 0;
		}
	}
	
	return 1;
}

int main(void)
{
//	freopen("B15711_input.txt", "r", stdin);
	
	cin >> T;
	
	eratos();
	
	while(T--)
	{
		long long a, b;
		cin >> a >> b;
		
		a += b;
		
		if(a <= 3)
		{
			cout << "NO\n";
			continue;
		}
		
		if(a % 2 == 0)	
		{
			cout << "YES\n";
		}
		else
		{
			if(check(a-2) == 1)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}	
	}

	return 0;
}
