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
int cnt;

void solve(int sum, int idx)
{
	if(idx == N+1)
	{
		if(sum == S)
		{
			cnt++;
		}
		
		return;
	}
	
	solve(sum + num[idx], idx+1);
	solve(sum, idx+1);
}

int main(void)
{
//	freopen("B1182_input.txt", "r", stdin);
	
	cin >> N >> S;
		
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	solve(0, 1);
	
	if(S == 0)
	{
		cnt--;
	}
	
	cout << cnt;
	
	return 0;
}
