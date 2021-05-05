#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int indegree[32010];
vector<int> graph[32010];
int visited[32010];
vector<int> result;

void topologySort()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			pq.push(i);
		}
	}
	
	while(!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		
		result.push_back(x);
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int next = graph[x][i];
			
			if(--indegree[next] == 0)
			{
				pq.push(next);
			}
		}
	}
}

int main(void)
{
//	freopen("B1766_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		indegree[to]++;
		graph[from].push_back(to);
	}
	
	topologySort();
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
