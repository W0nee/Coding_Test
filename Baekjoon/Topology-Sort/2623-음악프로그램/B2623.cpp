#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[1010];
int degree[1010];
int result[1010];
bool Flag = true;

void topology()
{
	queue<int> q;
	
	for(int i = 1; i <= N; i++)
	{
		if(degree[i] == 0)
		{
			q.push(i);
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(q.empty())
		{
			Flag = false;
			return;
		}
		
		int x = q.front();
		q.pop();
		result[i] = x;
		
		for(int j = 0; j < graph[x].size(); j++)
		{
			int y = graph[x][j];
			
			if(--degree[y] == 0)
			{
				q.push(y);
			}
		}
	}
}

int main(void)
{
//	freopen("B2623_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int list[1010];
		int cnt;
		cin >> cnt;
		
		for(int j = 1; j <= cnt; j++)
		{
			cin >> list[j];
		}
		
		for(int j = 1; j < cnt; j++)
		{
			graph[list[j]].push_back(list[j+1]);
			degree[list[j+1]]++;
		}
	}
	
	topology();
	
	if(Flag)
	{
		for(int i = 1; i <= N; i++)
		{
			cout << result[i] << endl;
		}
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
