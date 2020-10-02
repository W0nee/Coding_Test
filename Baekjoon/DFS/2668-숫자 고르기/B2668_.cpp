#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num[110];
int visited[110];
int finished[110];
int parent[110];
int cycle[110];

void DFS(int here)
{
	if(visited[here] == 1)
	{
		return;
	}
	
	visited[here] = 1;
	
	int next = num[here];
	
	if(visited[next] == 0)
	{
		parent[next] = here;
		DFS(next);
	}
	else if(finished[next] == 0)
	{
		parent[next] = here;
		
		int arrive = next;
		cycle[arrive] = 1;
		
		for(int i = parent[arrive]; i != arrive; i = parent[i])
		{
			cycle[i] = 1;
		}
	}
	
	finished[here] = 1;
}

int main(void)
{
//	freopen("B2668_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		parent[i] = i;
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(finished[i] == 0)
		{
			DFS(i);
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		if(cycle[i] == 1)
		{
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	for(int i = 1; i <= N; i++)
	{
		if(cycle[i] == 1)
		{
			cout << i << endl;
		}
	}
	
	return 0;
}
