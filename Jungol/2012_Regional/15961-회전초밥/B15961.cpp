#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
int d, k, coupon;
int sushi[6000010];
int visited[3010];
int Max;

int main(void)
{
//	freopen("B2531_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N >> d >> k >> coupon;
	
	for(int i = 0; i < N; i++)
	{
		cin >> sushi[i];
		sushi[N+i] = sushi[i];
	}

	int left = 0;
	int right = 0;
	int cnt = 0;
	
	while(left <= right && right < 2*N)
	{
		if(right-left < k)
		{
			if(visited[sushi[right]] == 0)
			{
				visited[sushi[right]] = 1;
				cnt++;
			}
			else
			{
				visited[sushi[right]]++;
			}
			
			right++;
		}
		else
		{
			visited[sushi[left]]--;
			
			if(visited[sushi[left]] == 0)
			{
				cnt--;
			}
			
			left++;
		}
		
		Max = max(Max, cnt + (visited[coupon] ? 0 : 1));
	}
	
	cout << Max;
	
	return 0;
}
