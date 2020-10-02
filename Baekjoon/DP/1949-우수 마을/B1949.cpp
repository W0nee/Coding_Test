#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[10010];
int people[10010];
int visited[10010];
int dp[10010][3];

int solve(int x, int select)
{
	if(dp[x][select] != 0)
	{
		return dp[x][select];	
	}
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		int nx = graph[x][i];
		
		if(visited[nx] == 0)
		{
			if(select == 0)
			{
				visited[nx] = 1;
				dp[x][select] += max(people[nx] + solve(nx, 1), solve(nx, 0));
				visited[nx] = 0;
			}
			else if(select == 1)
			{
				visited[nx] = 1;
				dp[x][select] += solve(nx, 0);
				visited[nx] = 0;
			}
		}
	}		
	
	return dp[x][select];
}

int main(void)
{
//	freopen("B1949_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> people[i];
	}

	for (int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin>> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	cout << max(solve(1, 0), people[1] + solve(1, 1));
	
	return 0;
}
