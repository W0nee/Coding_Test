#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
int x, y, dir;
int Map[60][60];
bool Flag = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int left_dir(int dir)
{
	if(dir == 0) return 3;
	else if(dir == 1) return 0;
	else if(dir == 2) return 1;
	else if(dir == 3) return 2;
}

int back_dir(int dir)
{
	if(dir == 0) return 2;
	else if(dir == 1) return 3;
	else if(dir == 2) return 0;
	else if(dir == 3) return 1;
}

int check(int x, int y)
{
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(Map[nx][ny] == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

void solve(int x, int y, int dir, int stage)
{
	if(Flag)
	{
		return;
	}
	
	// 1. 현재 위치를 청소한다.
	if(stage == 1)
	{
		Map[x][y] = 2;	
		stage = 2;
	}
	
	// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	if(stage == 2)
	{
		// d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		if(check(x, y) == 1)
		{
			int ndir = back_dir(dir);
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			if(Map[nx][ny] == 1)
			{
				Flag = true;
				return;	
			}
		}	
		
		// c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		if(check(x, y) == 1)
		{
			int ndir = back_dir(dir);
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			if(Map[nx][ny] != 1)
			{
				solve(nx, ny, dir, 2);
				return;	
			}
		}
		
		// a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		int ndir = left_dir(dir);
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];
		if(Map[nx][ny] == 0)
		{
			solve(nx, ny, ndir, 1);
			return;
		}	
		
		// b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		if(Map[nx][ny] != 0)
		{
			solve(x, y, ndir, 2);	
		}
	}
}

int main(void)
{
//	freopen("B14503_input.txt", "r", stdin);
	
	cin >> row >> col;
	cin >> x >> y >> dir;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve(x, y, dir, 1);
	
	int cnt = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(Map[i][j] == 2) cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
