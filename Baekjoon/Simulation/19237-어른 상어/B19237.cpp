#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct SHARK
{
	int x;
	int y;
	int dir;
	int up[5];
	int down[5];
	int left[5];
	int right[5];
}SHARK;

typedef struct node
{
	int num;
	int smell;
}VISITED;

typedef struct node
{
	int num;
	int x;
	int y;
	int dir;
}node;

int N, M, K;
int Map[21][21];
VISITED visited[21][21]; // [»ó¾î¹øÈ£, ³¿»õ½Ã°£] 
SHARK shark[410];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int safe(int x, int y)
{
	if(x >= 1 && y >= 1 && x <= N && y <= N)
	{
		return 1;	
	}
	else
	{
		return 0;	
	}
}

void time()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(visited[i][j].num != 0)
			{
				visited[i][j].before = 0;
				visited[i][j].smell--;
				
				if(visited[i][j].smell == 0)
				{
					visited[i][j].num = 0;
				}	
			}
		}
	}
}

void BFS(queue<node> &q)
{
	vector<node> v; 
	
	int cnt = q.size();
	while(cnt--)
	{
		int num = q.front().num;
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		
		bool move = false;
		for(int i = 1; i <= 4; i++)
		{
			int ndir;
			if(dir == 1) ndir = shark[num].up[i];	
			else if(dir == 2) ndir = shark[num].down[i];
			else if(dir == 3) ndir = shark[num].left[i];	
			else if(dir == 4) ndir = shark[num].right[i];		
			
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			// ¾Æ¹«³¿»õ°¡ ¾ø´Â Ä­ 
			if(safe(nx, ny) == 1 && visited[nx][ny].smell == 0)
			{
				move = true;
				
				v.push_back({num, nx, ny, ndir});
				
				break;
			}
		}
		
		if(!move)
		{
			for(int i = 1; i <= 4; i++)
			{
				int ndir;
				if(dir == 1) ndir = shark[num].up[i];	
				else if(dir == 2) ndir = shark[num].down[i];
				else if(dir == 3) ndir = shark[num].left[i];	
				else if(dir == 4) ndir = shark[num].right[i];		
				
				int nx = x + dx[ndir];
				int ny = y + dy[ndir];
				
				// ÀÚ±â³¿»õ°¡ ÀÖ´Â Ä­ 
				if(safe(nx, ny) == 1 && visited[nx][ny].num == num)
				{
					v.push_back({num, nx, ny, ndir});
					
					break;
				}
			}	
		}
	}	
	
	for(int i = 0; i < v.size(); i++)
	{
		int num = v[i].num;
		int nx = v[i].x;
		int ny = v[i].y;
		int ndir = v[i].dir;
		
		// »ó¾î°¡ ÀÖ´Â Ä­ -> Àâ¾Æ¸ÔÈû 
		if(visited[nx][ny].num != 0 && visited[nx][ny].num != num)
		{
			continue;
		}
		
		shark[num].x = nx;
		shark[num].y = ny;
		shark[num].dir = ndir;
		visited[nx][ny].num = num;
		visited[nx][ny].smell = K+1;
		
		q.push({num, nx, ny, ndir});
	}
	
	time();
}

int main(void)
{
//	freopen("B19237_input.txt", "r", stdin);

	cin >> N >> M >> K;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] != 0)
			{
				shark[Map[i][j]].x = i;
				shark[Map[i][j]].y = j;
			}
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> shark[i].dir;
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> shark[i].up[1] >> shark[i].up[2] >> shark[i].up[3] >> shark[i].up[4];
		cin >> shark[i].down[1] >> shark[i].down[2] >> shark[i].down[3] >> shark[i].down[4];
		cin >> shark[i].left[1] >> shark[i].left[2] >> shark[i].left[3] >> shark[i].left[4];
		cin >> shark[i].right[1] >> shark[i].right[2] >> shark[i].right[3] >> shark[i].right[4];
	}
	
	queue<node> q;
	for(int i = 1; i <= M; i++)
	{
		q.push({i, shark[i].x, shark[i].y, shark[i].dir});
		visited[shark[i].x][shark[i].y].num = i;
		visited[shark[i].x][shark[i].y].smell = K;
	}
	
	for(int i = 1; i <= 1000; i++)
	{	
		BFS(q);
		
		if(q.size() == 1)
		{
			cout << i;
			return 0;
		}
		else if(q.size() >= 2 && i == 1000)
		{
			cout << -1;
			return 0;
		}	
	}
	
	return 0;
}
