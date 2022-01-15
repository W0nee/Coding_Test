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

int T;
int N, K;
int indegree[1010];
int build_time[1010];
int result_time[1010];
vector<int> graph[1010];
int win;

void topology_sort()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			result_time[i] = build_time[i];
		}
	}
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		if(x == win)
		{
			break;
		}
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			
			result_time[y] = max(result_time[y], result_time[x] + build_time[y]);
			
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
			cin >> build_time[i];
			
			graph[i].clear();
			indegree[i] = 0;
			build_time[i] = 0;
			result_time[i] = 0;
		}
		
		for(int i = 1; i <= K; i++)
		{
			int from, to;
			cin >> from >> to;
			
			indegree[to]++;
			graph[from].push_back(to);	
		}
		
		cin >> win;
		
		topology_sort();
		
		cout << result_time[win] << "\n";
	}
	
	return 0;
}
