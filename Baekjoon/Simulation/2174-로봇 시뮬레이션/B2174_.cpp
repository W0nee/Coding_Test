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

typedef struct node
{
	int x;
	int y;
	int dir;
}node;

int row, col;
int robotNum, cmdNum;
int Map[110][110];
node robot[110];
bool Flag = false;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= col && 1 <= y && y <= row)
	{
		return 1;
	}
	
	return 0;
}

void move(int num, char cmd)
{
	int x = robot[num].x;
	int y = robot[num].y;
	
	if(cmd == 'L')
	{
		robot[num].dir = (robot[num].dir-1) == -1 ? 3 : robot[num].dir-1;
	}
	else if(cmd == 'R')
	{
		robot[num].dir = (robot[num].dir+1) == 4 ? 0 : robot[num].dir+1;
	}
	else if(cmd == 'F')
	{
		int dir = robot[num].dir;
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		
		if(safe(nx, ny))
		{
			if(Map[ny][nx] != 0)
			{
				cout << "Robot " << num << " crashes into robot " << Map[ny][nx];
				Flag = true;
				return;
			}
			
			robot[num].x = nx;
			robot[num].y = ny;
			
			Map[y][x] = 0;
			Map[ny][nx] = num;
		}
		else
		{
			cout << "Robot " << num << " crashes into the wall";
			Flag = true;
			return;
		}
	}
}

int main(void)
{
//	freopen("B2583_input.txt", "r", stdin);
	
	cin >> col >> row >> robotNum >> cmdNum;
	
	for(int i = 1; i <= robotNum; i++)
	{
		int robotX, robotY;
		char robotDir;
		
		cin >> robotX >> robotY >> robotDir;
		
		Map[robotY][robotX] = i;
		
		if(robotDir == 'N')
		{
			robot[i] = {robotX, robotY, 0};	
		}
		else if(robotDir == 'E')
		{
			robot[i] = {robotX, robotY, 1};	
		}
		else if(robotDir == 'S')
		{
			robot[i] = {robotX, robotY, 2};	
		}
		else if(robotDir == 'W')
		{
			robot[i] = {robotX, robotY, 3};	
		}
	}
	
	for(int i = 1; i <= cmdNum; i++)
	{
		int num, cnt;
		char cmd;
		
		cin >> num >> cmd >> cnt;
		
		for(int k = 1; k <= cnt; k++)
		{
			move(num, cmd);
			
			if(Flag)
			{
				return 0;
			}
		}
	}
	
	cout << "OK";
	
	return 0;
}
