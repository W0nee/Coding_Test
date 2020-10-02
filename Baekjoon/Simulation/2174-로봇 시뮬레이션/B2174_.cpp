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
	if(cmd == 'L')
	{
		int dir = robot[num].dir;
		dir -= 1;
		if(dir == -1) dir = 3;
		
		robot[num].dir = dir;
	}
	else if(cmd == 'R')
	{
		int dir = robot[num].dir;
		dir = (dir + 1) % 4;
		
		robot[num].dir = dir;
	}
	else if(cmd == 'F')
	{
		int x = robot[num].x;
		int y = robot[num].y;
		int dir = robot[num].dir;
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
//		cout << nx << " " << ny << endl;
		
		if(safe(nx, ny) == 0)
		{
			cout << "Robot " << num << " crashes into the wall" << endl;
			Flag = true;
			return;
		}
		
		if(Map[ny][nx] == 0)
		{
			Map[y][x] = 0;
			Map[ny][nx] = num;
			
			robot[num].x = nx;
			robot[num].y = ny;
		}
		else
		{
			cout << "Robot " << num << " crashes into robot " << Map[ny][nx] << endl;
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
