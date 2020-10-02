#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int coin[15];
int cnt;

bool cmp(int a, int b)
{
	if(a > b)
	{
		return true;
	}
	
	return false;
}

int main(void)
{
//	freopen("B11047_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}
	
	sort(coin+1, coin+N+1, cmp);
	
	int now = K;
	int coinIdx = 1;
	while(1)
	{
		if(now >= coin[coinIdx])
		{
			cnt++;
			now -= coin[coinIdx];
		}
		else
		{
			coinIdx++;
		}
		
		if(now == 0)
		{
			break;
		}
	}
	
	cout << cnt;
	
	return 0;
}
