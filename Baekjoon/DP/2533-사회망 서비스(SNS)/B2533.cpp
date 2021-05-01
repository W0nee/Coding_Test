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
vector<int> graph[1000010];
int dp[1000010][2];
int Min = INF;

int solve(int before, int now, int early)
{
	if(dp[now][early] != 0)
	{
		return dp[now][early];
	}
	
	for(int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];
		
		if(before != next)
		{
			if(early == 0)
			{
				dp[now][early] += solve(now, next, 1) + 1;	
			}
			else
			{
				dp[now][early] += min(solve(now, next, 1) + 1, solve(now, next, 0) + 0);	
			}
		}
	}
	
	return dp[now][early];
}

int main(void)
{
//	freopen("B2533_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	Min = min(solve(0, 1, 0) + 0, solve(0, 1, 1) + 1);
	
	cout << Min;
	
	return 0;
}
