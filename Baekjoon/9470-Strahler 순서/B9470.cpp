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
int K, M, P;
int indegree[1010];
int val[1010];
vector<int> graph[1010];
vector<int> check[1010];
int ans;

void topology()
{
	queue<int> q;
	
	for(int i = 1; i <= M; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
			val[i] = 1;
		}
	}
	
	while(!q.empty())
	{		
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			check[graph[x][i]].push_back(x);
			
			if(--indegree[graph[x][i]] == 0)
			{
				q.push(graph[x][i]);
				
				int Max = 0;
				int MaxCnt = 0;
				for(int k = 0; k < check[graph[x][i]].size(); k++)
				{
					Max = max(Max, val[check[graph[x][i]][k]]);
				}
				
				for(int k = 0; k < check[graph[x][i]].size(); k++)
				{
					if(Max == val[check[graph[x][i]][k]])
					{
						MaxCnt++;
					}
				}
				
				if(MaxCnt >= 2)
				{
					val[graph[x][i]] = Max+1;
				}
				else
				{
					val[graph[x][i]] = Max;
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B9470_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> T;
	
	while(T--)
	{		
		cin >> K >> M >> P;
		
		ans = 0;
		for(int i = 1; i <= M; i++)
		{
			val[i] = 0;
			indegree[i] = 0;
			graph[i].clear();
			check[i].clear();
		}
		
		for(int i = 1; i <= P; i++)
		{
			int from, to;
			cin >> from >> to;
			
			indegree[to]++;
			graph[from].push_back(to);
		}
		
		topology();
		
		for(int i = 1; i <= M; i++)
		{
			ans = max(ans, val[i]);
		}
		
		cout << K << " " << ans << endl;
	}
	
	return 0;
}
