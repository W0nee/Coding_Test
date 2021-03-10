#include <stdio.h>
#include <stdlib.h>
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

int N, M;
int parent[1000010];
int check[1000010];
vector<pair<int, int>> result;
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
//	freopen("B14595_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		Union(from, to);
	}
	
	for(int i = 1; i <= N; i++)
	{
		result.push_back({parent[i], i});
	}
	
	sort(result.begin(), result.end());
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i].first << " " << result[i].second << "\n";
	}
	
//	int n = 0;
//	for(int i = 1; i <= N; i++)
//	{
//		
//		
//		if(result[i].second < n)
//		{
//			continue;
//		}
//		
//		if(result[i].first != result[i+1].first)
//		{
//			n = result[i].second;
//			
//			cout << n << endl;
//			
//			cnt++;
//		}
//	}
	
	cout << cnt;
	
	return 0;
}
