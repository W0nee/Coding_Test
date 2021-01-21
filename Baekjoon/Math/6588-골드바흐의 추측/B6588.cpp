#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int num;
int dp[1000010];
vector<int> prime;

void eratos()
{
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i <= sqrt(1000000); i++)
	{
		if(dp[i] == 1)
		{
			continue;
		}
		
		for(int j = i+i; j <= 1000000; j += i)
		{
			dp[j] = 1;
		}
	}
	
	for(int i = 3; i <= 1000000; i++)
	{
		if(dp[i] == 0)
		{
			prime.push_back(i);
		}
	}
}

int main(void)
{
//	freopen("B6588_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	eratos();
	
	while(1)
	{
		cin >> num;
		
		if(num == 0)
		{
			return 0;
		}
		
		bool Flag = false;
		
		for(int i = 0; i < prime.size(); i++)
		{
			int num1 = prime[i];
			int num2 = num - prime[i];
			
			if(num2 <= 2)
			{
				break;
			}
			
			if(dp[num2] == 0)
			{
				cout << num << " = " << num1 << " + " << num2 << "\n";
				
				Flag = true;
				break;
			}
		}
		
		if(!Flag)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}
