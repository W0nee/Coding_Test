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

#define ll long long
#define INF 1111111111

int N, M;
vector<pair<ll, ll>> graph[20010];
int start, arrive;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
	if(a.second > b.second)
	{
		return true;
	}
	
	return false;
}

void BFS()
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> pq;
	ll visited[100010] = {0};
	
	pq.push({INF, start});
	visited[start] = INF;
	
	while(!pq.empty())
	{
		ll now = pq.top().second;
		ll nowCost = pq.top().first;
		pq.pop();
		
		if(now == arrive)
		{
			cout << visited[arrive] << "\n";
			return;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			ll next = graph[now][i].first;
			ll nextCost = graph[now][i].second;
			
			ll Min = min(visited[now], nextCost);
			
			if(visited[next] < Min)
			{
				pq.push({nextCost, next});
				visited[next] = min(visited[now], nextCost);
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
