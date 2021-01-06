#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int room[1000010];
int first, second;

long long solve()
{
	long long cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		room[i] -= first;
		cnt++;	
	}	
	
	for(int i = 1; i <= N; i++)
	{
		if(room[i] <= 0)
		{
			continue;
		}
		
		int second_cnt = 0;
		if(room[i] % second == 0)
		{
			second_cnt = room[i] / second;
		}
		else
		{
			second_cnt = room[i] / second + 1;
		}
		
		cnt += second_cnt;
	}
	
	return cnt;
}

int main(void)
{
//	freopen("B13458_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> room[i];
	}
	
	cin >> first >> second;
	
	cout << solve();
	
	return 0;
}
