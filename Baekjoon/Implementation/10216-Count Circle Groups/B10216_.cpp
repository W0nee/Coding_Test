#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node 
{
	int x;
	int y;
	int r;
}node;

int T;
int N;
node area[3010];
vector<int> graph[3010];
int visited[3010];

int possible(int a, int b)
{
	int x1 = area[a].x;
	int y1 = area[a].y;
	int r1 = area[a].r;
	
	int x2 = area[b].x;
	int y2 = area[b].y;
	int r2 = area[b].r;
	
	if(r1+r2 >= sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0)))
	{
		return 1;
	}
	
	return 0;
}

void BFS(int x)
{
	queue<int> q;
	
	q.push(x);
	visited[x] = 1;
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int next = graph[x][i];
			
			if(visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B10216_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> area[i].x >> area[i].y >> area[i].r;
			
			visited[i] = 0;
			graph[i].clear();
		}
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(i == j || possible(i, j) == 0)
				{
					continue;
				}
				
				graph[i].push_back(j);
			}
		}
		
		int cnt = 0;
		
		for(int i = 1; i <= N; i++)
		{
			if(visited[i] == 0)
			{
				BFS(i);
				cnt++;
			}
		}
		
		cout << cnt << "\n";
	}
	
	return 0;
}
