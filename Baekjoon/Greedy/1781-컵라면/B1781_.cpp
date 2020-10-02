#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int parent[200010];
int ans;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first > b.first)
	{
		return true;
	}
	else if(a.first == b.first)
	{
		if(a.second < b.second)
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
//	freopen("B1781_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int deadline, cost;
		cin >> deadline >> cost;
		
		v.push_back({cost, deadline});
		
		parent[i] = i;
	}
	
	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < N; i++)
	{
		int check = Find(v[i].second);
		
		if(check == 0)
		{
			continue;
		}
		
		Union(check, check-1);
		
		ans += v[i].first;
	}
	
	cout << ans;
	
	return 0;
}
