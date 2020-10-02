#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[510];
int indegree[510];
int time[510];
int result[510];

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
		
		for(int j = 0; j < graph[x].size(); j++)
		{
			int y = graph[x][j];
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
//	freopen("B2252_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int to = 1; to <= N; to++)
	{
		cin >> time[to];
		
		while(1)
		{
			int from;
			cin >> from;
			
			if(from == -1)
			{
				break;
			}
			
			graph[from].push_back(to);
			indegree[to]++;
		}
	}
	
	topology();
	
	for(int i = 1; i <= N; i++)
	{
		cout << result[i] << "\n";
	}
	
	return 0;
}
