#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int F;
map<string, int> name;
int parent[200010];
int cnt[200010];

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

int Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if(a != b)
	{
		cnt[a] += cnt[b];
		cnt[b] = cnt[a];
	
		if(a < b)
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}	
	}
	
	return cnt[a];
}

int main(void)
{
//	freopen("B4195_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> T;
	
	while(T--)
	{
		cin >> F;

		name.clear();
		for(int i = 1; i <= 200000; i++)
		{
			parent[i] = i;
			cnt[i] = 1;
		}
		
		int nameCnt = 0;		
		for(int i = 1; i <= F; i++)
		{
			string a, b;
			cin >> a >> b;
			
			if(name[a] == 0)
			{
				name[a] = ++nameCnt;
			}
			
			if(name[b] == 0)
			{
				name[b] = ++nameCnt;
			}
			
			cout << Union(name[a], name[b]) << "\n";
		}
	}
	
	return 0;
}
