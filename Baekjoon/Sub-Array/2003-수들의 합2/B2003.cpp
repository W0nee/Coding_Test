#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int num[10010];
int presum[10010];
int ans;

int main(void)
{
//	freopen("B2003_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		presum[i] = presum[i-1] + num[i];
	}
	
	int left = 0;
	int right = 0;
	
	while(left <= right && right <= N)
	{
		if(presum[right]-presum[left] < K)
		{
			right++;
		}
		else
		{
			if(presum[right]-presum[left] == K)
			{
				ans++;
			}
			
			left++;
		}
	}
	
	cout << ans;
	
	return 0;
}
