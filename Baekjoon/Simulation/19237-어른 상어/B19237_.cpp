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
	int before;	
}node;

typedef struct temp
{
	int num;
	int x;
	int y;
	int dir;
}temp;

int N, M, K;
int Map[21][21];
node visited[21][21]; // [상어번호, 냄새시간, 자기냄새로 이동시, 전에 자기냄새였는지 유무] 
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

void BFS()
{
	vector<temp> v;
	
	for(int k = M; k >= 1; k--)
	{
		// 죽은 상어 
		if(shark[k].x == -1)
		{
			continue;
		}
		
		int x = shark[k].x;
		int y = shark[k].y;
		int dir = shark[k].dir;
		
		bool move = false;
		for(int i = 1; i <= 4; i++)
		{
			int ndir;
			if(dir == 1) ndir = shark[k].up[i];	
			else if(dir == 2) ndir = shark[k].down[i];
			else if(dir == 3) ndir = shark[k].left[i];	
			else if(dir == 4) ndir = shark[k].right[i];		
			
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			// 아무냄새가 없는 칸 
			if(safe(nx, ny) == 1 && visited[nx][ny].smell == 0)
			{
				move = true;
				
				v.push_back({k, nx, ny, ndir});
				
				break;
			}
		}
		
		if(!move)
		{
			for(int i = 1; i <= 4; i++)
			{
				int ndir;
				if(dir == 1) ndir = shark[k].up[i];	
				else if(dir == 2) ndir = shark[k].down[i];
				else if(dir == 3) ndir = shark[k].left[i];	
				else if(dir == 4) ndir = shark[k].right[i];			
				
				int nx = x + dx[ndir];
				int ny = y + dy[ndir];
				
				// 자기냄새가 있는 칸 
				if(safe(nx, ny) == 1 && visited[nx][ny].num == k)
				{
					v.push_back({k, nx, ny, ndir});
					
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
		
		// 상어가 있는 칸 -> 잡아먹힘 
		if(visited[nx][ny].num != 0 && visited[nx][ny].num != num)
		{
			int other = visited[nx][ny].num;
			shark[other].x = -1;
		}
		
		shark[num].x = nx;
		shark[num].y = ny;
		shark[num].dir = ndir;
		visited[nx][ny].num = num;
		visited[nx][ny].smell = K+1;
	}
	
	time();
}

int check()
{
	for(int i = 2; i <= M; i++)
	{
		if(shark[i].x != -1)
		{
			return 0;
		}
	}
	
	return 1;
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
	
	for(int i = 1; i <= M; i++)
	{
		visited[shark[i].x][shark[i].y].num = i;
		visited[shark[i].x][shark[i].y].smell = K;
	}
	
	for(int i = 1; i <= 1000; i++)
	{
		BFS();
		
//		for(int i = 1; i <= N; i++)
//		{
//			for(int j = 1; j <= N; j++)
//			{
//				cout << visited[i][j].num << "(" << visited[i][j].smell << ") ";
//			}
//			cout << endl;
//		}
//		cout << endl;
		
		if(check() == 1)
		{
			cout << i;
			return 0;
		}
	}
	
	cout << -1;
	return 0;
}
