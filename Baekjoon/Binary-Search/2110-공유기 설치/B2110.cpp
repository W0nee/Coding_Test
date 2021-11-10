#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, C;
int house[200010];
int Max;

bool cmp(int a, int b)
{
	if(a < b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int check(int dist)
{
	int cnt = 1;
	int prev = house[1];
	
	for(int i = 2; i <= N; i++)
	{
		if(house[i] - prev >= dist)
		{
			cnt++;
			prev = house[i];
		}
	}
	
	if(cnt >= C)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void bs()
{
	int left = 1;
	int right = house[N];
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
		if(check(mid))
		{
			Max = max(Max, mid);
			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}	
}

int main(void)
{
//	freopen("B2110_input.txt", "r", stdin);
	
	cin >> N >> C;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> house[i];
	}
	
	sort(house+1, house+N+1, cmp);
	
	bs();
	
	cout << Max;
	
	return 0;
}
