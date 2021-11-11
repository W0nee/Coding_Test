#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int tree[1000010];
int Max;

long long check(int h)
{
	long long sum = 0;
	
	for(int i = 1; i <= N; i++)
	{
		if(h <= tree[i])
		{
			sum += tree[i] - h;
		}
	}
	
	if(sum >= M)
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
//	freopen("B2805_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> tree[i];
	}
	
	int left = 1;
	int right = 1000000000;
	
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
	
	cout << Max;
	
	return 0;
}
