#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[10010];
int people[10010];
int visited[10010];
int dp[10010][2];

void DFS(int x)
{
	dp[x][0] = 0;
	dp[x][1] = people[x];
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i]] == 0)
		{
			visited[graph[x][i]] = 1;
			DFS(graph[x][i]);
			dp[x][0] += max(dp[graph[x][i]][0], dp[graph[x][i]][1]);
			dp[x][1] += dp[graph[x][i]][0];
		}
	}
}

int main(void)
{
//	freopen("B1949_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> people[i];
	}
	
	int from, to;
	while(cin >> from >> to)
	{
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	DFS(1);
	
	cout << max(dp[1][0], dp[1][1]);
	
	return 0;
}
