#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, K;
int dp[1000010];
vector<int> card;

int check(int num)
{
	vector<int> digit;
	while(num > 0)
	{
		int temp = num % 10;
		num /= 10;
		
		digit.push_back(temp);
	}
	
	int cnt = 0;
	for(int i = 0; i < digit.size(); i++)
	{
		for(int j = 0; j < card.size(); j++)
		{
			if(digit[i] == card[j])
			{
				cnt++;
				break;
			}
		}
	}
	
	if(cnt == digit.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int solve(int num)
{	
	if(num == 1)
	{
		return 0;
	}
	
	if(dp[num] != -1)
	{
		return dp[num];
	}
	dp[num] = 99999999;
	
	if(check(num) == 1)
	{
		dp[num] = min(dp[num], solve(num / num));
	}
	else
	{
		for(int i = 2; i <= sqrt(num); i++)
		{
			if(check(i) == 0)
			{
				continue;
			}
			
			if(num % i == 0)
			{
				dp[num] = min(dp[num], solve(num / i) + 1);	
			}
		}
	}
	
	return dp[num];
}

int main(void)
{
//	freopen("B12783_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{		
		card.clear();
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			
			card.push_back(num);
		}
		
		cin >> M;
		
		for(int i = 1; i <= M; i++)
		{
			memset(dp, -1, sizeof(dp));
			
			cin >> K;
		
			int ans = solve(K);
			
			if(ans == 99999999)
			{
				cout << "-1\n";
			}
			else
			{
				cout << ans << "\n";
			}
		}
	}
	
	return 0;
}
