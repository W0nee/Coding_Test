#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int from;
	int to;
	int n;
}node;

int N;
int dp[10010];
int Switch[10010];
int Light[10010];
int arr[10010];
vector<node> list;
vector<int> order;
int Max;
int MaxNum;

bool cmp(node a, node b)
{
	if(a.from < b.from)
	{
		return true;
	}
	else if(a.from == b.from)
	{
		if(a.to < b.to)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

int solve(int idx)
{
	if(idx == list.size()-1)
	{
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	for(int i = idx+1; i < list.size(); i++)
	{
		if(list[idx].to < list[i].to)
		{
			int val = solve(i) + 1;
			
			if(dp[idx] < val)
			{
				dp[idx] = val;
				arr[list[idx].n] = list[i].n;
			}	
		}
	}
	
	return dp[idx];
}

void print(int idx)
{
	if(arr[idx] == 0)
	{
		return;
	}
	
	print(arr[idx]);
	order.push_back(arr[idx]);
}

int main(void)
{
//	freopen("J2251_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> Switch[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		cin >> Light[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Switch[i] == Light[j])
			{
				list.push_back({i, j, Switch[i]});
			}
		}
	}
	
	sort(list.begin(), list.end(), cmp);
	
	for(int i = 0; i < list.size(); i++)
	{
		int val = solve(i) + 1;
		
		if(Max < val)
		{
			Max = val;
			MaxNum = list[i].n;
		}
	}
	
	cout << Max << "\n";
	order.push_back(MaxNum);
	print(MaxNum);
	
	sort(order.begin(), order.end());
	
	for(int i = 0; i < order.size(); i++)
	{
		cout << order[i] << " ";
	}
	
	return 0;
}
