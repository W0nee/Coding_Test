#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, K, W;
vector<int> graph[1010];
int indegree[1010];
int time[1010];
int result[1010];

void topology()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			result[i] = time[i];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(q.empty())
		{
			return;
		}
		
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			result[y] = max(result[y], result[x] + time[y]);
			
			if(--indegree[y] == 0)
			{
				q.push(y);
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
		}
		memset(time, 0, sizeof(time));
		memset(result, 0, sizeof(result));
		memset(indegree, 0, sizeof(indegree));
		
		for(int i = 1; i <= N; i++)
		{
			cin >> time[i];
		}
		
		for(int i = 1; i <= K; i++)
		{
			int from, to;
			cin >> from >> to;	
			
			graph[from].push_back(to);
			indegree[to]++;
		}
		
		cin >> W;
		
		topology();
		
		cout << result[W] << "\n";
	}
	
	return 0;
}
