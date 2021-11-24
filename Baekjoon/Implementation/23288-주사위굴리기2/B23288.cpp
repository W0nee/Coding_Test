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

int Map[30][30];
int dice[7];
int row, col, dir, K;
int x, y;
int result;

// 동남서북 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void convert()
{
	int temp[7];
	for(int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}
	
	if(dir == 0)
	{
		dice[3] = temp[1];
		dice[6] = temp[3];
		dice[4] = temp[6];
		dice[1] = temp[4];
	}
	else if(dir == 1)
	{
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
		dice[1] = temp[2];
	}
	else if(dir == 2)
	{
		dice[1] = temp[3];
		dice[4] = temp[1];
		dice[6] = temp[4];
		dice[3] = temp[6];
 	}
 	else if(dir == 3)
 	{
 		dice[5] = temp[6];
		dice[1] = temp[5];	
		dice[2] = temp[1];
		dice[6] = temp[2];
	}
}

int get_point(int x, int y, int value)
{	
	queue<pair<int, int>> q;
	int visited[30][30] = {0};
	
	q.push({x, y});
	visited[x][y] = 1;
	int cnt = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny))
			{
				if(Map[nx][ny] == value && visited[nx][ny] == 0)
				{
					q.push({nx, ny});
					visited[nx][ny] = 1;
					cnt++;	
				}		
			}
		}
	}
	
	return value * cnt;
}

void rolling()
{
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	
	// 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
	if(safe(nx, ny) == 0)
	{
		if(dir == 0) dir = 2;
		else if(dir == 1) dir = 3;
		else if(dir == 2) dir = 0;
		else if(dir == 3) dir = 1;
		
		nx = x+dx[dir];
		ny = y+dy[dir];
	}
	
	// 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
	result += get_point(nx, ny, Map[nx][ny]);
	
	// 주사위 변환 
	convert();
	
	// A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
	if(dice[6] > Map[nx][ny])
	{
		dir = (dir+1) % 4;
	}
	else if(dice[6] < Map[nx][ny])
	{
		dir = dir-1;
		if(dir == -1)
		{
			dir = 3;
		}
	}
	
	x = nx;
	y = ny;
}

int main(void)
{
//	freopen("B14499_input.txt", "r", stdin);
	
	cin >> row >> col >> K;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= 6; i++)
	{
		dice[i] = i;
	}
	
	x = 1;
	y = 1;
	dir = 0;

	while(K--)
	{
		rolling();	
	}
	
	cout << result;
	
	return 0;
}
