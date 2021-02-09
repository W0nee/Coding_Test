#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

int T;
ll num;
ll ans;
ll dp[110];
int coin[3] = {1, 10, 25};

ll solve(int sum)
{
	if(sum == 0)
	{
		return 0;
	}
	else if(sum < 0)
	{
		return 987654321;
	}
	
	if(dp[sum] != 0)
	{
		return dp[sum];
	}
	dp[sum] = 987654321;
	
	for(int i = 0; i < 3; i++)
	{
		dp[sum] = min(dp[sum], solve(sum - coin[i]) + 1);
	}
	
	return dp[sum];
}

int main(void)
{
//	freopen("B1398_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		ans = 0;

		cin >> num;
		
		while(num > 0)
		{
			ans += solve(num % 100);
			num /= 100;	
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
