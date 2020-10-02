#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N, T, G;
int visited[100010];
int ans;

int safe(int x)
{
	if(x > 99999)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int cal(int x)
{
	int digit = 0;
	
	while(x != 0)
	{
		x /= 10;
		digit++;
	}
	
	return digit;
}

void BFS(int x)
{
	queue<int> q;
	
	q.push(x);
	visited[x] = 0;
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		
		if(x == G)
		{
			return;
		}
		
		for(int i = 1; i <= 2; i++)
		{
			if(i == 1)
			{
				if(safe(x+1) == 1 && visited[x+1] == -1 && visited[x] + 1 <= T)
				{
					q.push(x+1);
					visited[x+1] = visited[x] + 1;
				}
			}
			else
			{
				int digit = cal(x*2);
				int nx = x*2;
				nx -= pow(10, digit-1);
				
				if(safe(x*2) == 1 && safe(nx) == 1 && visited[nx] == -1 && visited[x] + 1 <= T)
				{
					q.push(nx);
					visited[nx] = visited[x] + 1;
				}
			}	
		}
	}
}

int main(void)
{
//	freopen("B16937_input.txt", "r", stdin);
	
	cin >> N >> T >> G;
	
	memset(visited, -1, sizeof(visited));
	
	BFS(N);
	
	if(visited[G] == -1)
	{
		cout << "ANG";
	}
	else
	{
		cout << visited[G];
	}
	
	return 0;
}
