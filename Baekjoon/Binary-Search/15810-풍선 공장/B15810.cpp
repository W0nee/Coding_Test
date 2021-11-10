#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int staff[1000010];
long long Min = 1000000000010;

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

int check(long long time)
{
	long long cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		cnt += time / staff[i];
	}
	
	if(cnt < M)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
//	freopen("B15810_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> staff[i];
	}
	
	long long left = 1;
	long long right = 1000000000000;
	
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		if(check(mid))
		{
			left = mid+1;
		}
		else
		{
			Min = min(Min, mid);
			right = mid-1;
		}
	}
	
	cout << Min;
		
	return 0;
}
