#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M;
ll time[100010];
ll Max, Min;

int check(ll mid)
{
	ll cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		cnt += mid / time[i];
	}
	
	if(cnt >= M)
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
//	freopen("B3079_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> time[i];
		
		Max = max(Max, time[i]);
	}
	
	ll left = 0;
	ll right = M * Max;
	
	while(left <= right)
	{
		ll mid = (left + right) / 2;
		
		if(check(mid))
		{
			Min = mid;
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	
	cout << Min;
	
	return 0;
}
