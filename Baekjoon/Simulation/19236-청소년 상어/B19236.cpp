#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct FISH
{
	int x;
	int y;
	int dir;
	int live;
}FISH;

int Map[4][4];
FISH fish[20];
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

void fish_move(int sx, int sy)
{
	for(int i = 1; i <= 16; i++)
	{
		if(fish[i].live == 0)
		{
			continue;
		}
		
		int cnt = 8;
		while(cnt--)
		{
			int x = fish[i].x;
			int y = fish[i].y;
			int xpos = x + dx[fish[i].dir];
			int ypos = y + dy[fish[i].dir];
			
			// 상어를 만나거나 or 밖으로 나가는 경우 
			if(safe(xpos, ypos) == 0 || (xpos == sx && ypos == sy))
			{
				fish[i].dir = (fish[i].dir+1) % 8;	
				continue;
			}
			// 빈공간인 경우 
			else if(Map[xpos][ypos] == 0)
			{
				fish[i].x = xpos;
				fish[i].y = ypos;
				
				Map[xpos][ypos] = Map[x][y];
				Map[x][y] = 0;
			
				break;
			}
			else
			{		
				int tempX = fish[Map[x][y]].x;
				int tempY = fish[Map[x][y]].y;
				fish[Map[x][y]].x = fish[Map[xpos][ypos]].x;
				fish[Map[x][y]].y = fish[Map[xpos][ypos]].y;
				fish[Map[xpos][ypos]].x = tempX;
				fish[Map[xpos][ypos]].y = tempY;
				
				int tempMap = Map[x][y];
				Map[x][y] = Map[xpos][ypos];
				Map[xpos][ypos] = tempMap;
				
				break;
			}	
		}
	}
}

void DFS(int sx, int sy, int sdir, int eat)
{
	// copy
	int MapCopy[4][4];
	FISH fishCopy[20];
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
	
	// 물고기 잡아먹음
	int eat_fish = Map[sx][sy];
	fish[eat_fish].live = 0;
	Map[sx][sy] = 0;
	
	// 최댓값 계산 
	Max = max(Max, eat+eat_fish);
	
	// 물고기 이동
	fish_move(sx, sy);
	
	// 상어 이동 
	for(int i = 1; i <= 3; i++)
	{
		int sxpos = sx+dx[sdir]*i;	
		int sypos = sy+dy[sdir]*i;
		
		if(safe(sxpos, sypos) == 1 && Map[sxpos][sypos] != 0)
		{
			DFS(sxpos, sypos, fish[Map[sxpos][sypos]].dir, eat+eat_fish);
		}
	} 
	
	// restore 
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
			int fishNum, dir;
			cin >> fishNum >> dir;
			
			Map[i][j] = fishNum;
			
			fish[fishNum].x = i;
			fish[fishNum].y = j;
			fish[fishNum].dir = dir-1;
			fish[fishNum].live = 1;
		}
	}
	
	DFS(0, 0, fish[Map[0][0]].dir, 0); 
	
	cout << Max;
	
	return 0;
}

