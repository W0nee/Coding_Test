#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

long long N, M;
long long ride[10010];
long long check[10010];
long long time = 70000000000;

long long cal(long long time)
{
	long long cnt = M;
	
	for(int i = 1; i <= M; i++)
	{
		cnt += (time / ride[i]);
	}
	
	return cnt;
}

int main(void)
{
//	freopen("B1561_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		cin >> ride[i];
	}
	
	if(N <= M)
	{
		cout << N;
		return 0;
	}
	
	long long left = 0;
	long long right = 60000000000;
	
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		if(cal(mid) >= N)
		{
			right = mid-1;
			time = mid;
		}		
		else
		{
			left = mid+1;
		}
	}	
	
	// (time-1)까지 탄 사람의 수 구하기 
	long long check = M;
	for(int i = 1; i <= M; i++)
	{
		check += (time-1) / ride[i];
	}
	
	
	// (time)에 딱 탄 사람의 수 구함으로써, 마지막 사람 구하기 -> 나머지가 0 
	long long rest = N-check;
	int cnt = 0;
	for(int i = 1; i <= M; i++)
	{
		if(time % ride[i] == 0)
		{
			cnt++;
		}
		
		if(cnt == rest)
		{
			cout << i;
			break;
		}
	}
	
	return 0;
}
