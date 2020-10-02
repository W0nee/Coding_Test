#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int G, P;
int parent[100010];
int g[100010];
int cnt;

int Find(int a)
{
	if(parent[a] == a)
	{
		return a;
	}
	else
	{
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if(a != b)
	{
		if(a < b)
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}
	}
}

int main(void)
{
//	freopen("B10775_input.txt", "r", stdin);

	cin >> G >> P;
	
	for(int i = 1; i <= G; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= P; i++)
	{	
		cin >> g[i];
	}
	
	for(int i = 1; i <= P; i++)
	{
		int check = Find(g[i]);
		
		if(check == 0)
		{
			break;
		}
		
		Union(check, check-1);
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
