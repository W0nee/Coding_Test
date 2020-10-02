#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int dir;	
	int live;
}FISH;

int Map[4][4];
FISH fish[17];
int Max;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int safe(int x, int y)
{
	if(x >= 0 && y >= 0 && x < 4 && y < 4)
	{
		return 1;	
	}
	else
	{
		return 0;	
	}
}

void moveFish(int sharkX, int sharkY)
{
	// 물고기는 작은 번호 순으로 이동 
	for(int k = 1; k <= 16; k++)
	{
		// 물고기가 죽은 경우 
		if(fish[k].live == 0)
		{
			continue;
		}

		int fishX, fishY;
		int fishDir = fish[k].dir;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(Map[i][j] == k)
				{
					fishX = i;
					fishY = j;
				}
			}
		}
		
		// 8방향 확인 
		for(int i = 0; i < 8; i++)
		{	 
			int ndir = (fishDir + i) % 8;
			int nx = fishX + dx[ndir];
			int ny = fishY + dy[ndir];
			
			// 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸
			if(safe(nx, ny) == 1 && !(nx == sharkX && ny == sharkY))
			{
				// 바뀐 방향 적용 
				fish[Map[fishX][fishY]].dir = ndir;
				
				int tempMap = Map[fishX][fishY];
				Map[fishX][fishY] = Map[nx][ny];
				Map[nx][ny] = tempMap;		
				
				break;
			}
		}
	}
}

void solve(int sharkX, int sharkY, int sharkDir, int eat)
{
	Max = max(Max, eat);
	
	int MapCopy[4][4];
	FISH fishCopy[17];
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			MapCopy[i][j] = Map[i][j];
		}
	}
	for(int i = 1; i <= 16; i++)
	{
		fishCopy[i] = fish[i];
	}	
	
	moveFish(sharkX, sharkY);
	
	for(int i = 1; i <= 3; i++)
	{
		int nx = sharkX + dx[sharkDir] * i;
		int ny = sharkY + dy[sharkDir] * i;
		
		//  물고기가 없는 칸으로는 이동할 수 없다. 
		if(safe(nx, ny) == 1 && Map[nx][ny] != 0)
		{
			eat += Map[nx][ny];
			fish[Map[nx][ny]].live = 0;
			int ndir = fish[Map[nx][ny]].dir;
			int temp = Map[nx][ny];
			Map[nx][ny] = 0;
			
			solve(nx, ny, ndir, eat);
			
			Map[nx][ny] = temp;
			fish[Map[nx][ny]].live = 1;
			eat -= Map[nx][ny];
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			Map[i][j] = MapCopy[i][j];
		}
	}
	for(int i = 1; i <= 16; i++)
	{
		fish[i] = fishCopy[i];
	}
}

int main(void)
{
//	freopen("B19236_input.txt", "r", stdin);
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int num, dir;
			cin >> num >> dir;
			
			Map[i][j] = num;s
			
			fish[num].dir = dir-1;
			fish[num].live = 1;
		}
	}
	
	Max = Map[0][0];
	fish[Map[0][0]].live = 0;
	int sharkDir = fish[Map[0][0]].dir;
	Map[0][0] = 0;
	
	solve(0, 0, sharkDir, Max);
	
	cout << Max;
	
	return 0;
}
