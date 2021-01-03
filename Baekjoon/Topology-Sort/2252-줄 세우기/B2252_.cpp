#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[32010];
int indegree[32010];
vector<int> result;

void topology()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			result.push_back(i);
		}
	}
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			if(--indegree[graph[x][i]] == 0)
			{
				q.push(graph[x][i]);
				result.push_back(graph[x][i]);
			}
		}
	}
}

int main(void)
{
//	freopen("B2252_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		indegree[to]++;
		graph[from].push_back(to);
	}
	
	topology();
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
