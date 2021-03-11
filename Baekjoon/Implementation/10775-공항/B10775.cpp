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
int parent[100010];
int airplane[100910];
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
//	freopen("B14594_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> airplane[i];
	}
	
	for(int i = 1; i <= M; i++)
	{		
		int idx = Find(airplane[i]);
		
		if(idx == 0)
		{
			break;
		}
		else
		{
			parent[idx] = idx-1;
			cnt++;	
		}
	}
	
	cout << cnt;
	
	return 0;
}
