#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int N, K;
vector<int> graph[1010];
int indegree[1010];
int build[1010];
int time[1010];
int W;

void topology()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			build[i] = time[i];
		}
	}
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			build[graph[x][i]] = max(build[graph[x][i]], build[x] + time[graph[x][i]]);
			
			if(--indegree[graph[x][i]] == 0)
			{
				q.push(graph[x][i]);
			}
		}
	}
}

int main(void)
{
//	freopen("B1005_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N >> K;
		
		for(int i = 1; i <= N; i++)
		{
			W = 0;
			build[i] = 0;
			indegree[i] = 0;
			graph[i].clear();
			
			cin >> time[i];
		}
		
		for(int i = 1; i <= K; i++)
		{
			int from, to;
			cin >> from >> to;
			
			indegree[to]++;
			graph[from].push_back(to);
		}
		
		cin >> W;
		
		topology();
		
		cout << build[W] << "\n";
	}
	
	return 0;
}
