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
		
		int left = Find(from);
		int right = Find(to);
		
		if(left == right)
		{
			continue;
		}
		
		for(int i = left; i <= right; i++)
		{
//			parent[i] = max(left, right);
			parent[i] = right;
		}	
	}
	
	for(int i = 1; i <= N; i++)
	{
		Find(i);
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(check[parent[i]] == 0)
		{
			check[parent[i]] =1;
			cnt++;
		}	
	}
	
	cout << cnt;
	
	return 0;
}
