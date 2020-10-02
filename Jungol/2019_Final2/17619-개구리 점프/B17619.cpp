#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x1;
	int x2;
	int idx;
}node;

int N, Q;
node Log[100010];
int parent[100010];

bool cmp(node a, node b)
{
	if(a.x1 < b.x1)
	{
		return true;
	}
	else if(a.x1 == b.x1)
	{
		if(a.x2 < b.x2)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

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
//	freopen("B17619_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++)
	{
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		
		Log[i].x1 = x1;
		Log[i].x2 = x2;
		Log[i].idx = i;
		
		parent[i] = i;
	}
	
	sort(Log+1, Log+N+1, cmp);
	
	int MaxLen = Log[1].x2;
	int MaxIdx = Log[1].idx;
	
	for(int i = 2; i <= N; i++)
	{
		if(MaxLen - Log[i].x1 >= 0)
		{
			Union(MaxIdx, Log[i].idx);
		}
		
		if(MaxLen < Log[i].x2)
		{
			MaxLen = Log[i].x2;
			MaxIdx = Log[i].idx;
		}
	}
	
	for(int i = 1; i <= Q; i++)
	{
		int from, to;
		cin >> from >> to;
		
		if(Find(from) == Find(to))
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	
	return 0;
}
