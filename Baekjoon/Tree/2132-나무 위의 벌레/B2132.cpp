#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[10010];
int fruit[10010];
int visited[10010];
int Max;
int MaxIdx;

void BFS(int start)
{
	queue<pair<int, int>> q;
	q.push({start, fruit[start]});
	visited[start] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int sum = q.front().second;
		q.pop();
		
		if(Max <= sum)
		{
			if(Max == sum)
			{
				MaxIdx = min(MaxIdx, x);
			}
			else
			{
				MaxIdx = x;
			}
			
			Max = sum;
		}
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int xpos = graph[x][i];
			
			if(visited[xpos] == 0)
			{
				q.push({xpos, sum + fruit[xpos]});
				visited[xpos] = 1;	
			}
		}
	}	
}

int main(void)
{
//	freopen("B2132_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> fruit[i];
	}
	
	int from, to;
	while(cin >> from >> to)
	{
        graph[from].push_back(to);
        graph[to].push_back(from);	
	}
    
    Max = -1;
    memset(visited, 0, sizeof(visited));
    BFS(1);
    
    Max = -1;
    int End = MaxIdx;
    memset(visited, 0, sizeof(visited));
    BFS(MaxIdx);
	
	int MinIdx = min(End, MaxIdx);
	
	cout << Max << " " << MinIdx;
	
	return 0;
}
