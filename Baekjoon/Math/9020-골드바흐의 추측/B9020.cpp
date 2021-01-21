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
	
	for(int i = 2; i <= 1000000; i++)
	{
		if(dp[i] == 0)
		{
			prime.push_back(i);
		}
	}
}

int main(void)
{
//	freopen("B9020_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> T;
	
	eratos();
	
	while(T--)
	{
		cin >> num;
		
		bool Flag = false;
		pair<int, int> result;
		int Min = 99999999;
		
		for(int i = 0; i < prime.size(); i++)
		{
			int num1 = prime[i];
			int num2 = num - prime[i];
			
			if(num2 <= 1)
			{
				break;
			}
			
			if(dp[num2] == 0)
			{
				if(Min > abs(num1 - num2))
				{
					Min = abs(num1 - num2);
					result.first = num1;
					result.second = num2;
					
					Flag = true;
				}
			}
		}
		
		cout << result.first << " " << result.second << "\n";
	}

	return 0;
}
