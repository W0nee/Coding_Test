#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef struct node
{
	int h;
	int cost;
}node;

int N, S;
node display[300010];
long long dp[300010];
long long Max;

bool cmp(node a, node b)
{
	if(a.h < b.h)
	{
		return true;
	}
	else if(a.h == b.h)
	{
		if(a.cost < b.cost)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

int binary(int left, int right, int find)
{
	int idx = N+1;
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
		if(display[mid].h >= find)
		{
			right = mid-1;
			idx = mid;		
		}
		else
		{
			left = mid+1;
		}
	}
	
	return idx;
}

long long solve(int idx)
{
	if(idx > N)
	{
		return 0;
	}
	
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	
	int h = display[idx].h;
	int lowIdx = binary(idx, N, h+S);
	
	dp[idx] = max(dp[idx], display[idx].cost + solve(lowIdx));
	dp[idx] = max(dp[idx], solve(idx+1));
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2515_input.txt", "r", stdin);
	
	cin >> N >> S;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> display[i].h >> display[i].cost;
	}
	
	sort(display+1, display+N+1, cmp);
	
	cout << solve(1);
	
	return 0;
}
