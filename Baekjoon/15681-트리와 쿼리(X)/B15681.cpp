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

int N, R, Q;
vector<int> graph[100010];
int visited[100010];
int dp[100010];

int solve(int x)
{
	if(dp[x] != 0)
	{
		return dp[x];
	}
	dp[x] = 1;
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i]] == 0)
		{
			visited[graph[x][i]] = 1;
			dp[x] += solve(graph[x][i]);
		}
	}
	
	return dp[x];
}

int main(void)
{
//	freopen("B15681_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> R >> Q;
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[R] = 1;
	solve(R);
	
	for(int i = 1; i <= Q; i++)
	{
		int q;
		cin >> q;
		
		cout << solve(q) << "\n";
	}
	
	return 0;
}
