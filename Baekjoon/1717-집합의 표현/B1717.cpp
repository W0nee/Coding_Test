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

int N, M;
int parent[1000010];

int Find(int a)
{
	if(parent[a] != a)
	{
		return parent[a] = Find(parent[a]);
	}
	else
	{
		return a;
	}	
} 

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if(a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

int main(void)
{
//	freopen("B1717_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= M; i++)
	{
		int oper, a, b;
		cin >> oper >> a >> b;
		
		if(oper == 0)
		{
			Union(a, b);
		}
		else
		{
			if(Find(a) == Find(b))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
	
	return 0;
}
