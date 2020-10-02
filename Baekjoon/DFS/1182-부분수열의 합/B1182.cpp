#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int num[30];
int candidate[30];
int ans;

void cal(int cnt)
{
	int sum = 0;
	
	for(int i = 1; i < cnt; i++)
	{
		sum += candidate[i];
	}
	
	if(sum == S)
	{
		ans++;
	}
}

void DFS(int idx, int cnt)
{
	if(cnt != 1)
	{
		cal(cnt);
	}
	
	if(cnt >= N+1)
	{
		return;
	}
	
	for(int i = idx; i <= N; i++)
	{
		candidate[cnt] = num[i];
		DFS(i+1, cnt+1);
	}
}

int main(void)
{
//	freopen("B1182_input.txt", "r", stdin);
	
	cin >> N >> S;
		
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	DFS(1, 1);
	
	cout << ans;
	
	return 0;
}
