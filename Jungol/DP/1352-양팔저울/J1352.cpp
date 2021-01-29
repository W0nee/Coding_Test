#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
int choo[40];
int dp[15010][40];
int goal;

void solve(int sum, int idx)
{
	// idx >= N (X), idx > N (O) -> Áß¿ä 
	if(idx > N)
	{
		return;
	}
	
	if(dp[sum][idx] != 0)
	{
		return;
	}
	dp[sum][idx] = 1;
	
	solve(sum + choo[idx], idx+1);
	solve(abs(sum - choo[idx]), idx+1);
	solve(sum, idx+1);
}

int main(void)
{
//	freopen("J1352_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> choo[i];
	}
	
	solve(0, 0);
	
	cin >> T;
	
	while(T--)
	{
		cin >> goal;
		
		if(goal > 15000)
		{
			cout << "N ";
			continue;
		}
		
		if(dp[goal][N] == 1)
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
	
	return 0;
}
