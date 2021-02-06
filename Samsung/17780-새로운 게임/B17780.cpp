#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int dir;	
}node;

int N, M;
int Map[15][15];
deque<int> pos[15][15];
node horse[12];
bool Flag = false;

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x & x <= N && 1 <= y && y <= N)
	{
		return 1;	
	}

	return 0;	
}

int reverse_dir(int dir)
{
	if(dir == 1) return 2;
	else if(dir == 2) return 1;
	else if(dir == 3) return 4;
	else if(dir == 4) return 3;
}

int can_move(int x, int y, int horseNum)
{
	if(pos[x][y].size() == 1)
	{
		return 1;
	}
	else if(pos[x][y].size() >= 2)
	{
		if(pos[x][y][0] == horseNum)
		{
			return 1;
		}
		
		return 0;
	}
}

void stack_horse(int x, int y, int nx, int ny, int color)
{
	if(color == 1)
	{
		while(pos[x][y].size() != 0)
		{
			int n = pos[x][y][pos[x][y].size()-1];
			horse[n].x = nx;
			horse[n].y = ny;
			
			pos[nx][ny].push_back(n);
			pos[x][y].pop_back();
		}
	}
	else if(color == 0)
	{
		while(pos[x][y].size() != 0)
		{
			int n = pos[x][y][0];
			horse[n].x = nx;
			horse[n].y = ny;
			
			pos[nx][ny].push_back(n);
			pos[x][y].pop_front();
		}	
	}
}

void horse_move()
{
	for(int k = 1; k <= M; k++)
	{
		int x = horse[k].x;
		int y = horse[k].y;
		int dir = horse[k].dir;
		
		if(can_move(x, y, k) == 0)
		{
			continue;
		}
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		// 체스판을 벗어나는 경우에는 파란색과 같은 경우
		if(safe(nx, ny) == 0)
		{
			horse[k].dir = reverse_dir(dir);
			
			dir = horse[k].dir;
			nx = x + dx[dir];
			ny = y + dy[dir];
			
			// 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우
			if(safe(nx, ny) == 0 || Map[nx][ny] == 2)
			{
				continue;
			}
			
			if(Map[nx][ny] == 1)
			{
				stack_horse(x, y, nx, ny, 1);
			}
			else if(Map[nx][ny] == 0)
			{
				stack_horse(x, y, nx, ny, 0);
			}		
			
			// 말이 4개 이상 쌓이면 종료 
			if(pos[nx][ny].size() >= 4)
			{
				Flag = true;
				return;
			}	
		}
		else
		{
			if(Map[nx][ny] == 2)
			{
				horse[k].dir = reverse_dir(dir);
			
				dir = horse[k].dir;
				int nnx = x + dx[dir];
				int nny = y + dy[dir];
				
				// 방향을 반대로 한 후에 이동하려는 칸이 파란색인 경우
				if(safe(nnx, nny) == 0 || Map[nnx][nny] == 2)
				{
					continue;
				}
					
				if(Map[nnx][nny] == 1)
				{
					stack_horse(x, y, nnx, nny, 1);
				}
				else if(Map[nnx][nny] == 0)
				{
					stack_horse(x, y, nnx, nny, 0);
				}
				
				// 말이 4개 이상 쌓이면 종료 
				if(pos[nnx][nny].size() >= 4)
				{
					Flag = true;
					return;
				}			
			}
			else if(Map[nx][ny] == 1)
			{
				stack_horse(x, y, nx, ny, 1);
			}
			else if(Map[nx][ny] == 0)
			{
				stack_horse(x, y, nx, ny, 0);
			}		
			
			// 말이 4개 이상 쌓이면 종료 
			if(pos[nx][ny].size() >= 4)
			{
				Flag = true;
				return;
			}	
		}
	}
}

void solve()
{
	int turn = 1;
	
	while(turn <= 1000)
	{
		horse_move();	
		
		if(Flag)
		{
			cout << turn;
			return;
		}
		
		turn++;
	}
	
	cout << "-1";
}

int main(void)
{
//	freopen("B17780_input.txt", "r", stdin);

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> horse[i].x >> horse[i].y >> horse[i].dir;
		
		pos[horse[i].x][horse[i].y].push_back(i);
	}
	
	solve();
	
	return 0;
}
