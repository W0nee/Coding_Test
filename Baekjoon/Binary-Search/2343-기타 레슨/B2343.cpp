#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int lec[100010];
int Min = 1000000010;

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

int check(int size)
{
	int cnt = 1;
	int sum = 0;
	
	for(int i = 1; i <= N; i++)
	{
		if(lec[i] > size)
		{
			return 1;
		}
		
		if(sum + lec[i] <= size)
		{
			sum += lec[i];
		}
		else
		{
			cnt++;
			sum = lec[i];
		}
	}
	 
	if(cnt > M)
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
//	freopen("B2343_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> lec[i];
	}
	
	int left = 1;
	int right = 1000000000;
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
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
