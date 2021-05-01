#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
vector<int> graph[10010];
int num[10010];
int visited[10010];
int dp[10010][2];
int Max;

int solve(int now, int best)
{
	if(dp[now][best] != 0)
	{
		return dp[now][best];
	}
	
	for(int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];

		if(visited[next] == 0)
		{
			visited[next] = 1;
			
			if(best == 0)
			{
				dp[now][best] += max(solve(next, 0), solve(next, 1) + num[next]);
			}
			else
			{
				dp[now][best] += solve(next, 0);
			}	
			
			visited[next] = 0;
		}
	}
	
	return dp[now][best];
}

int main(void)
{
//	freopen("B1949_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	Max = max(solve(1, 0), solve(1, 1) + num[1]);
	
	cout << Max;
	
	return 0;
}
