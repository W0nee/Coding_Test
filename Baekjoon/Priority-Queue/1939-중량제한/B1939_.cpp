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

int N, M;
vector<pair<int, int>> graph[10010];
int start, arrive;
int Max;

int BFS(int mid)
{
	queue<int> q;
	int visited[10010] = {0};
	
	q.push(start);
	visited[start] = 1;
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if(now == arrive)
		{
			return 1;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(visited[next] == 0 && nextCost >= mid)
			{
				q.push(next);
				visited[next] = 1;
			}
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B1939_input.txt", "r", stdin);
	
	cin >> N >> M;

	for(int i = 1; i <= M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}
	
	cin >> start >> arrive;
	
	int left = 0;
	int right = 1000000000;
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
		if(BFS(mid) == 1)
		{
			Max = max(Max, mid);
			
			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}
	
	cout << Max;
	
	return 0;
}
