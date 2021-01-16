#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
int visited[1000010];

int BFS()
{
	queue<int> q;
	
	q.push(S);
	visited[S] = 1;
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if(now == G)
		{
			return 1;
		}
		
		for(int i = 0; i < 2; i++)
		{
			if(i == 0)
			{
				int next = now + U;
				
				if(1 <= next && next <= F && visited[next] == 0)
				{
					q.push(next);
					visited[next] = visited[now] + 1;
				}
			}
			else if(i == 1)
			{
				int next = now - D;
				
				if(1 <= next && next <= F && visited[next] == 0)
				{
					q.push(next);
					visited[next] = visited[now] + 1;
				}
			}	
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B5014_input.txt", "r", stdin);
	
	cin >> F >> S >> G >> U >> D;
	
	if(BFS())
	{
		cout << visited[G]-1;
	}
	else
	{
		cout << "use the stairs";
	}
	
	return 0;
}
