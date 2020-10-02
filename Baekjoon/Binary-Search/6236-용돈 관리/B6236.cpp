#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int money[100010];
int MaxMoney;
int Min = 999999999;

int cal(int withdraw)
{
	int now = withdraw;
	int cnt = 1;
	
	for(int i = 1; i <= N; i++)
	{
		if(money[i] <= now)
		{
			now -= money[i];
		}
		else
		{
			cnt++;
			now = withdraw;
			now -= money[i];
		}
	}
	
	return cnt;
}

int main(void)
{
//	freopen("B1865_input.txt", "r", stdin);
	
	cin >> N >> M;
		
	for(int i = 1; i <= N; i++)
	{
		cin >> money[i];
		
		if(MaxMoney < money[i])
		{
			MaxMoney = money[i];
		}
	}
	
	int left = MaxMoney;
	int right = 100000;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
		if(cal(mid) > M)
		{
			left = mid+1;
		}
		else
		{
			right = mid-1;
			Min = min(Min, mid);
		}
	}
	
	cout << Min;
	
	return 0;
}
