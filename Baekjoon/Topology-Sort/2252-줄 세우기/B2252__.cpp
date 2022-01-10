#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int indegree[33000];
vector<int> graph[33000];

queue<int> q;
vector<int> result;

void topology_sort()
{
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			
			if(--indegree[y] == 0)
			{
				q.push(y);
				result.push_back(y);
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
		
		graph[from].push_back(to);
		indegree[to]++;
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			result.push_back(i);
		}
	}
	
	topology_sort();
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
