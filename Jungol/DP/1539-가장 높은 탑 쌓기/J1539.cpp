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
	int a;
	int h;
	int w;
	int n;
}node;

int N;
int dp[110];
int arr[110];
int cnt[110];
vector<node> list;
int Max;
int MaxNum;

bool cmp(node a, node b)
{
	if(a.a > b.a)
	{
		return true;
	}
	else if(a.a == b.a)
	{
		if(a.w > b.w)
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
	
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	
	for(int i = idx+1; i < list.size(); i++)
	{
		if(list[idx].a > list[i].a && list[idx].w > list[i].w)
		{
			int val = solve(i) + list[i].h;
			
			if(dp[idx] < val)
			{
				dp[idx] = val;
				arr[list[idx].n] = list[i].n;
				cnt[list[idx].n] = cnt[list[i].n] + 1;
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
	cout << arr[idx] << "\n";
}

int main(void)
{
//	freopen("J1539_input.txt", "r", stdin);

	for(int i = 1; i <= 100; i++)
	{
		cnt[i] = 1;
		arr[i] = 0;
	}
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int a, h, w;
		cin >> a >> h >> w;
		
		list.push_back({a, h, w, i});
	}
	
	sort(list.begin(), list.end(), cmp);
	
	for(int i = 0; i < list.size(); i++)
	{
		int val = solve(i) + list[i].h;

		if(Max < val)
		{
			Max = val;
			MaxNum = list[i].n;
		}
	}
	
	cout << cnt[MaxNum] << "\n";
	print(MaxNum);
	cout << MaxNum;
	
	return 0;
}
