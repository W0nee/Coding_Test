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
int parent[3010];
node area[3010];

int Find(int a)
{
	if(parent[a] == a)
	{
		return a;
	}
	
	return parent[a] = Find(parent[a]);
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
			
			parent[i] = i;
		}
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = i+1; j <= N; j++)
			{
				if(possible(i, j) == 0)
				{
					continue;
				}
				
				Union(i, j);
			}
		}
		
		map<int, int> check;
		int cnt = 0;
		
		for(int i = 1; i <= N; i++)
		{
			int a = Find(i);
			
			if(check[a] == 0)
			{
				check[a] = 1;
				cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
