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

int N, M;
int indegree[33000];
vector<int> graph[33000];

queue<int> q;
vector<int> result;

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
		int from = q.front();
		q.pop();
		
		for(int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i];
			
			if(--indegree[to] == 0)
			{
				q.push(to);
				result.push_back(to);
			}
		}
	}
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
