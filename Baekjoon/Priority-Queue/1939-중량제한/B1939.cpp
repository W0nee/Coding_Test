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

#define INF 1111111111

int N, M;
vector<pair<int, int>> graph[10010];
int start, arrive;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.second > b.second)
	{
		return true;
	}
	
	return false;
}

void BFS()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	int visited[100010] = {0};
	
	pq.push({INF, start});
	visited[start] = INF;
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(now == arrive)
		{
			cout << visited[arrive] << "\n";
			return;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			int Min = min(visited[now], nextCost);
			
			if(visited[next] < Min)
			{
				pq.push({nextCost, next});
				visited[next] = Min;
			}
		}
	}
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
	
	BFS();
	
	return 0;
}
