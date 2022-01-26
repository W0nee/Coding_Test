#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int Min = 987654321;
int ans;

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
			if(Min > visited[x] - 1)
			{
				Min = visited[x] - 1;
				ans = 1;
			}
			else if(Min == visited[x] - 1)
			{
				ans++;	
			}
			
			continue;
		}
		
		for(int i = 1; i <= 3; i++)
		{
			int nx;
			
			if(i == 1) nx = x + 1;
			else if(i == 2) nx = x - 1;
			else if(i == 3) nx = x * 2;
			
			if(!(0 <= nx && nx <= 100000))
			{
				continue;
			}
			
			if(visited[nx] == 0 || visited[x] + 1 <= visited[nx])
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
	cout << ans << endl;
	
	return 0;
}
