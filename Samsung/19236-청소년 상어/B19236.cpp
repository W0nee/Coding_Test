#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
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
	int live;
}FISH;

int Map[5][5];
FISH fish[17];
int sharkX, sharkY, sharkDir;
int eat;
int Max;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int safe(int x, int y)
{
	if(1 <= x & x <= 4 && 1 <= y && y <= 4)
	{
		return 1;	
	}

	return 0;	
}

void fish_move(int sharkX, int sharkY)
{
	for(int k = 1; k <= 16; k++)
	{
		if(fish[k].live == 0)
		{
			continue;
		}
		
		int x = fish[k].x;
		int y = fish[k].y;
		int dir = fish[k].dir;
		
		for(int i = 0; i < 8; i++)
		{
			int ndir = (fish[k].dir + i) % 8;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			if(safe(nx, ny) == 0 || (nx == sharkX && ny == sharkY))
			{
				continue;
			}
			
			if(Map[nx][ny] == 0)
			{
				fish[k].x = nx;
				fish[k].y = ny;
				fish[k].dir = ndir;
				
				int temp = Map[x][y];
				Map[x][y] = Map[nx][ny];
				Map[nx][ny] = temp;
				
				break;
			}
			else if(Map[nx][ny] >= 1)
			{
				fish[k].x = nx;
				fish[k].y = ny;
				fish[k].dir = ndir;
				
				fish[Map[nx][ny]].x = x;
				fish[Map[nx][ny]].y = y;
				
				int temp = Map[x][y];
				Map[x][y] = Map[nx][ny];
				Map[nx][ny] = temp;
				
				break;
			}
		}
	}
}

void shark_move(int sharkX, int sharkY, int sharkDir, int eat)
{
	Max = max(Max, eat);
	
	int temp_Map[5][5];
	FISH temp_fish[17];
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			temp_Map[i][j] = Map[i][j];
		}
	}
	
	for(int i = 1; i <= 16; i++)
	{
		temp_fish[i] = fish[i];
	}
	
	fish_move(sharkX, sharkY);
	
//	cout << "\n";
//	for(int i = 1; i <= 4; i++)
//	{
//		for(int j = 1; j <= 4; j++)
//		{
//			cout << Map[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	for(int i = 1; i <= 3; i++)
	{
		int nx = sharkX + dx[sharkDir] * i;
		int ny = sharkY + dy[sharkDir] * i;
		int ndir = fish[Map[nx][ny]].dir;
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		int temp = Map[nx][ny];
		
		if(Map[nx][ny] != 0)
		{
			fish[Map[nx][ny]].live = 0;
			Map[nx][ny] = 0;
			shark_move(nx, ny, ndir, eat+temp);
			Map[nx][ny] = temp;
			fish[Map[nx][ny]].live = 1;	
		}
	}
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			Map[i][j] = temp_Map[i][j];
		}
	}
	
	for(int i = 1; i <= 16; i++)
	{
		fish[i] = temp_fish[i];
	}
}

void init()
{
	sharkX = 1;
	sharkY = 1;
	sharkDir = fish[Map[sharkX][sharkY]].dir;
	eat += Map[sharkX][sharkY];
	
	fish[Map[sharkX][sharkY]].live = 0;
	Map[sharkX][sharkY] = 0;
}

void solve()
{
	init();
	
	shark_move(sharkX, sharkY, sharkDir, eat);
	
	cout << Max;
}

int main(void)
{
//	freopen("B19236_input.txt", "r", stdin);
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			int dir;
			cin >> Map[i][j] >> dir;
			
			fish[Map[i][j]] = {i, j, --dir, 1};
		}
	}
	
	solve();
	
	return 0;
}
