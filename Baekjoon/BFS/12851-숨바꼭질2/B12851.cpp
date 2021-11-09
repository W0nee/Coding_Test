#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N, K;
map<int, int> num;
int Min = 987654321;

int safe(int x)
{
	if(0 <= x && x <= 100000)
	{
		return 1;
	}
	
	return 0;
}

void BFS()
{
	queue<int> q;
	int visited[100010] = {0};
	
	q.push(N);
	visited[N] = 1;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		if(x == K)
		{
			Min = min(Min, visited[x]-1);
			num[visited[x]-1] += 1;
		}
		
		for(int i = 0; i <= 2; i++)
		{
			int nx;
			
			if(i == 0)
			{
				nx = x - 1; 
			}
			else if(i == 1)
			{
				nx = x + 1;
			}
			else 
			{
				nx = 2 * x;
			}
		
			if(safe(nx) == 1 && (visited[nx] == 0 || visited[x] + 1 <= visited[nx]))
			{
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
		}	
	}	
}


int main(void)
{
//	freopen("B12851_input.txt", "r", stdin);
	
	cin >> N >> K;

	BFS();
	
	cout << Min << endl;
	cout << num[Min] << endl;
	
	return 0;
}
