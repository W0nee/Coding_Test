#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int lan[10010];
long long Max;

bool cmp(int a, int b)
{
	if(a < b)
	{
		return true;
	}
	
	return false;
}

long long check(int size)
{
	long long sum = 0;
	
	for(int i = 1; i <= K; i++)
	{
		sum += lan[i] / size;
	}
	
	if(sum >= N)
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
//	freopen("B1654_input.txt", "r", stdin);
	
	cin >> K >> N;
	
	for(int i = 1; i <= K; i++)
	{
		cin >> lan[i];
	}
	
	sort(lan+1, lan+K+1, cmp);
	
	long long left = 1;
	long long right = lan[K];
	
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		if(check(mid))
		{
			Max = max(Max, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	
	cout << Max;
	
	return 0;
}
