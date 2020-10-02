#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M;
int Map[210][210];
int visited[210];
vector<int> city[210];
vector<int> plan;

int check()
{
	for(int i = 0; i < plan.size(); i++)
	{
		if(visited[plan[i]] == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

void BFS()
{
	queue<int> q;
	q.push(plan[0]);
	visited[plan[0]] = 1;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < city[x].size(); i++)
		{
			if(visited[city[x][i]] == 0)
			{
				visited[city[x][i]] = 1;
				q.push(city[x][i]);
			}
		}
	}
}

int main(void)
{
//	freopen("B1976_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 1)
			{
				city[i].push_back(j);
			}
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		int a;
		cin >> a;
		
		plan.push_back(a);
	}

	BFS();
	
	if(check())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}
