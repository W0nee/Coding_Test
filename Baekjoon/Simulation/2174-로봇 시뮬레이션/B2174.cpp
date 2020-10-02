#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Robot
{
	int x;
	int y;
	int dir;
}Robot;

int X, Y;
int N, M;
int Map[110][110]; // 0 : 이동가능, 나머지 : 로봇번호 
Robot robot[110]; 

int dx[4] = {0, 1, 0, -1}; // N: 0, E: 1, S: 2, W: 3
int dy[4] = {1, 0, -1, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= X && 1 <= y && y <= Y)
	{
		return 1;
	}
	
	return 0;
}

int Move(int num, char command, int cnt)
{
	for(int i = 1; i <= cnt; i++)
	{
		if(command == 'L')
		{
			robot[num].dir = (robot[num].dir-1) % 4;
			if(robot[num].dir == -1) robot[num].dir = 3;
		}
		else if(command == 'R')
		{
			robot[num].dir = (robot[num].dir+1) % 4;
		}
		else if(command == 'F')
		{
			int x = robot[num].x;
			int y = robot[num].y;
			int dir = robot[num].dir;
			
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(safe(nx, ny) == 1)
			{
				if(Map[nx][ny] != 0)
				{
					cout << "Robot " << num << " crashes into robot " << Map[nx][ny];
					return 1;	
				}	
			}
			else
			{
				cout << "Robot " << num << " crashes into the wall";
				return 1;
			}
			
			robot[num].x = nx;
			robot[num].y = ny;
				
			Map[x][y] = 0;
			Map[nx][ny] = num;
		}	
	}
	
	return 0;
}

int main(void)
{
//	freopen("B2174_input.txt", "r", stdin);
	
	cin >> X >> Y;

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		char dir;
		cin >> robot[i].x >> robot[i].y >> dir;
		
		if(dir == 'N') robot[i].dir = 0;
		else if(dir == 'E') robot[i].dir = 1;
		else if(dir == 'S') robot[i].dir = 2;
		else if(dir == 'W') robot[i].dir = 3;
		
		Map[robot[i].x][robot[i].y] = i;
	} 
	
	for(int i = 1; i <= M; i++)
	{
		int robotNum, exeCnt; 
		char command;
		
		cin >> robotNum >> command >> exeCnt;
		
		if(Move(robotNum, command, exeCnt))
		{
			return 0;
		}
	}
	
	cout << "OK";
	
	return 0;
}
