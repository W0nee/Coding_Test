#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num[110];
int visited[110];
int cnt;
bool check;

void DFS(int start, int x, int cnt)
{
	if(start == x && cnt != 1)
	{
		check = true;
		return;
	}
	
	if(visited[num[x]] == 0)
	{
		visited[num[x]] = 1;
		DFS(start, num[x], cnt+1);		
		if(check == false)
		{
			visited[num[x]] = 0;	
		}
	}
}

int main(void)
{
//	freopen("B2668_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
		{
			check = false;
			DFS(i, i, 1);
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 1)
		{
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 1)
		{
			cout << i << endl;
		}
	}
	
	return 0;
}
