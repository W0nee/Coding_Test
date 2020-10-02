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
vector<int> graph[1000010];
int visited[1000010];
int dp[1000010][2];

int solve(int x, int select)
{
	if(dp[x][select] != 0)
	{
		return dp[x][select];
	}
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i]] == 0)
		{
			if(select == 0)
			{
				visited[graph[x][i]] = 1;
				dp[x][select] += solve(graph[x][i], 1) + 1;
				visited[graph[x][i]] = 0;
			}
			else if(select == 1)
			{
				visited[graph[x][i]] = 1;
				dp[x][select] += min(solve(graph[x][i], 0), solve(graph[x][i], 1) + 1);
				visited[graph[x][i]] = 0;
			}
		}
	}
	
	return dp[x][select];
}

int main(void)
{
//	freopen("B2533_input.txt", "r", stdin);

	cin >> N;
	
	int from, to;
	while(cin >> from >> to)
	{
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	cout << min(solve(1, 0), solve(1, 1) + 1);
	
	return 0;
}
