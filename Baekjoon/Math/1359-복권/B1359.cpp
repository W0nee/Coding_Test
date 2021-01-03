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

int N, M, K;

void combination(int idx, int cnt, int n, int m, double &ans)
{
	if(cnt == m)
	{
		ans++;
		return;
	}
	
	for(int i = idx; i <= n; i++)
	{
		combination(i+1, cnt+1, n, m, ans);
	}
}

int main(void)
{
//	freopen("B1359_input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	
	double down = 0;
	combination(1, 0, N, M, down);
	
	double up = 0;
	double up1 = 0;
	double up2 = 0;
	for(int i = K; i <= M; i++, K++)
	{
		up1 = 0;
		up2 = 0;
		
		if(N-M < M-K)
		{
			continue;
		}
		
		combination(1, 0, M, K, up1);
		combination(1, 0, N-M, M-K, up2);
		
		up += up1 * up2;
	}
	
	printf("%.16f", up / down);
	
	return 0;
}
