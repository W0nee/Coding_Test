#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
	int a;
	int b;
	int cnt;
}node;

int A;
int B;
int resultA;
int resultB;
map<pair<int,int>, bool> visited;
int ans = -1;

void BFS()
{
	queue<node> q;
	q.push({0, 0, 0});
	visited[{0, 0}] = 1;
	
	while(!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int cnt = q.front().cnt;
		q.pop();
		
		if(a == resultA && b == resultB)
		{
			ans = cnt;
			return;
		}
		
		for(int i = 1; i <= 6; i++)
		{
			// Fill A
			if(i == 1)
			{
				if(visited[{A, b}] == 0)
				{
					q.push({A, b, cnt+1});
					visited[{A, b}] = 1;
				}
			}
			// Fill B
			else if(i == 2)
			{
				if(visited[{a, B}] == 0)
				{
					q.push({a, B, cnt+1});
					visited[{a, B}] = 1;
				}
			}
			// Move A to B
			else if(i == 3)
			{
				if(a + b > B)
				{
					if(visited[{a+b-B, B}] == 0)
					{
						q.push({a+b-B, B, cnt+1});
						visited[{a+b-B, B}] = 1;	
					}
				}
				else
				{
					if(visited[{0, a+b}] == 0)
					{
						q.push({0, a+b, cnt+1});
						visited[{0, a+b}] = 1;
					}
				}
			}
			// Move B to A
			else if(i == 4)
			{
				if(a + b > A)
				{
					if(visited[{A, a+b-A}] == 0)
					{
						q.push({A, a+b-A, cnt+1});
						visited[{A, a+b-A}] = 1;	
					}
				}
				else
				{
					if(visited[{a+b, 0}] == 0)
					{
						q.push({a+b, 0, cnt+1});
						visited[{a+b, 0}] = 1;	
					}
				}
			}
			// Empty A
			else if(i == 5)
			{
				if(visited[{0, b}] == 0)
				{
					q.push({0, b, cnt+1});
					visited[{0, b}] = 1;	
				}
			}
			// Empty B
			else if(i == 6)
			{
				if(visited[{a, 0}] == 0)
				{
					q.push({a, 0, cnt+1});
					visited[{a, 0}] = 1;	
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B14867_input.txt", "r", stdin);
	
	cin >> A >> B >> resultA >> resultB;
	
	BFS();
	
	cout << ans;
	
	return 0;
}
