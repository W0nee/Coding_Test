#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, L;
int parent[300010];
int visited[300010];

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
		parent[a] = b;	
	}
}

int main(void)
{
//	freopen("B9938_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N >> L;
	
	for(int i = 1; i <= L; i++)
	{
		parent[i] = i;
	}
		
	for(int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if(visited[a] == 0)
		{
			visited[a] = 1;
			Union(a, b);
		}
		else if(visited[b] == 0)
		{
			visited[b] = 1;
			Union(b, a);
		}
		else if(visited[Find(parent[a])] == 0)
		{
			visited[Find(parent[a])] = 1;
			Union(a, b);
		}
		else if(visited[Find(parent[b])] == 0)
		{
			visited[Find(parent[b])] = 1;
			Union(b, a);
		}
		else
		{
			cout << "SMECE\n";
			continue;
		}
		
		cout << "LADICA\n";
	}
	
	return 0;
}
