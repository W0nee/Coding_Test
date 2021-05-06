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
int win;

void topologySort()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		if(x == win)
		{
			return;
		}
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int next = graph[x][i];
			time[next] = max(time[next], build[x]);
			
			if(--indegree[next] == 0)
			{
				q.push(next);
				build[next] += time[next];
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
			graph[i].clear();
			indegree[i] = 0;
			build[i] = 0;
			time[i] = 0;
		}
		
		for(int i = 1; i <= N; i++)
		{
			cin >> build[i];
		}
		
		for(int i = 1; i <= K; i++)
		{
			int from, to;
			cin >> from >> to;
			
			indegree[to]++;
			graph[from].push_back(to);
		}
		
		cin >> win;
		
		topologySort();
		
		cout << build[win] << endl;
	}
	
	return 0;
}
