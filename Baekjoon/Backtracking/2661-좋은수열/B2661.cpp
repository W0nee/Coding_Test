#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100];
bool Flag = false;

int check(int cnt)
{
	for(int k = 2; k <= cnt/2; k++)
	{
		int forCnt = 0;
		int sameCnt = 0;
		
		for(int i = cnt, j = cnt-k; forCnt != k; i--, j--, forCnt++)
		{
			if(arr[i] == arr[j])
			{
				sameCnt++;
			}
		}
		
		if(sameCnt == k)
		{
			return 0;
		}
	}
	
	return 1;
}

void solve(int cnt)
{
	if(cnt == N+1)
	{
		Flag = true;
		return;
	}
	
	for(int i = 1; i <= 3; i++)
	{
		if(cnt-1 >= 1 && arr[cnt-1] == i)
		{
			continue;
		}
		
		arr[cnt] = i;
		
		if(check(cnt))
		{
			solve(cnt+1);	
		}
		
		if(Flag)
		{
			return;
		}
	}
}

int main(void)
{
//	freopen("B2661_input.txt", "r", stdin);

	cin >> N;
	
	solve(1);

	for(int i= 1; i <= N; i++)
	{
		cout << arr[i];
	}
	
	return 0;
}
