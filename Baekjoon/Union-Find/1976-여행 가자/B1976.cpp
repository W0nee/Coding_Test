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
int parent[210];
int road[1010];

int getParent(int a)
{
	if(parent[a] == a)
	{
		return a;
	}
	else
	{
		return parent[a] = getParent(parent[a]);
	}
}

void unionFind(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	
	if(a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	
	if(a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
//	freopen("B1976_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 1)
			{
				unionFind(i, j);
			}
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> road[i];
	}
	
	bool check = true;
	for(int i = 1; i <= M-1; i++)
	{
		if(findParent(road[i], road[i+1]) == 0)
		{
			check = false;
			break;
		}
	}
	
	if(check)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}
