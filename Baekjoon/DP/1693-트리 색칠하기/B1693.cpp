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
vector<int> graph[100010];
vector<int> tree[100010];
int dp[100010][20];
int Min = INF;

int solve(int before, int now, int color)
{
	if(dp[now][color] != 0)
	{
		return dp[now][color];
	}
	
	int colorSum = 0;
	
	for(int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];
		int Min = INF;
		
		if(before != next)
		{
			for(int nextColor = 1; nextColor <= 18; nextColor++)
			{
				if(color != nextColor)
				{
					Min = min(Min, solve(now, next, nextColor) + nextColor);
				}
			}	
			
			colorSum += Min;
		}
	}
	
	return dp[now][color] = colorSum;
}

int main(void)
{
//	freopen("B1693_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	for(int i = 1; i <= 18; i++)
	{
		Min = min(Min, solve(0, 1, i) + i);
	}
	
	cout << Min;
	
	return 0;
}
