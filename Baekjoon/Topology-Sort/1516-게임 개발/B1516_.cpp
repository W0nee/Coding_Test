#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int indegree[550];
int build_time[550];
int max_time[550];
int result_time[550];
vector<int> graph[550];

queue<int> q;
int total_time;

void topology_sort()
{
	while(!q.empty())
	{
		int from = q.front();
		q.pop();
		
		for(int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i];
			max_time[to] = max(max_time[to], result_time[from] + build_time[to]);
			
			if(--indegree[to] == 0)
			{
				q.push(to);
				result_time[to] = max_time[to];
			}
		}
	}
}

int main(void)
{
//	freopen("B1516_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int to = 1; to <= N; to++)
	{
		int time;
		cin >> time;
		
		build_time[to] = time;
		
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
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			result_time[i] = build_time[i];
		}
	}
	
	topology_sort();
	
	for(int i = 1; i <= N; i++)
	{
		cout << result_time[i] << "\n";
	}
	
	return 0;
}
