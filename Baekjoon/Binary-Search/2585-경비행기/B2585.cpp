#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, K;
int graph[1010][1010];
pair<int, int> pos[1010];
int Min = INF;

int BFS(int mid)
{
	queue<pair<int, int>> q;
	int visited[1010] = {0};
	
	q.push({0, 0});
	visited[0] = 1;
		
	while(!q.empty())
	{
		int now = q.front().first;
		int k = q.front().second;
		q.pop();
		
		for(int next = 1; next <= N+1; next++)
		{
			if(graph[now][next] <= mid && next == N+1)
			{
				return 1;
			}
			else if(visited[next] < visited[now] && graph[now][next] <= mid && k+1 <= K)
			{
				q.push({next, k+1});
				visited[next] = visited[now] + 1;
			}
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B2585_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	pos[0].first = 0;
	pos[0].second = 0;
	pos[N+1].first = 10000;
	pos[N+1].second = 10000;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	
	for(int i = 0; i <= N+1; i++)
	{
		for(int j = 0; j <= N+1; j++)
		{
			graph[i][j] = ceil(sqrt(pow(pos[i].first-pos[j].first, 2.0) + pow(pos[i].second-pos[j].second, 2.0)) / 10);
		}
	}
	
	int left = 0;
	int right = graph[0][N+1];
	
	while(left <= right)
	{	
		int mid = (left + right) / 2;
		
		if(BFS(mid) == 1)
		{
			Min = min(Min, mid);
			
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
