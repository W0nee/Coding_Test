#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int road[400][400];
int dp[400][400];

int solve(int from, int cnt)
{
	// N에 도착시 종료 
	if(from == N && cnt <= M)
	{
		return 0;
	}
	
	// M개의 도시를 전부돌았지만 최종 도착지가 N이 아니면 매우 작은 값 리턴  
	if(from != N && cnt >= M)
	{
		return -987654321;	
	}
	
	if(dp[from][cnt] != 0)
	{
		return dp[from][cnt];
	}
	dp[from][cnt] = -987654321;
	
	for(int to = from+1; to <= N; to++)
	{
		if(road[from][to] != 0)
		{
			dp[from][cnt] = max(dp[from][cnt], solve(to, cnt+1) + road[from][to]);
		}
	}
	
	return dp[from][cnt];
}

int main(void)
{
//	freopen("B2157_input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int from, to, grade;
		cin >> from >> to >> grade;
		
		if(road[from][to] != 0)
		{
			road[from][to] = max(road[from][to], grade);	
		}
		else
		{
			road[from][to] = grade;
		}
	}
	
	cout << solve(1, 1) << "\n";

	return 0;
}
