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
int startX, startY, N;
int Map[30][30];
int dice[7];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

int safe(int x, int y)
{
	if(0 <= x && x < row && 0 <= y && y < col)
	{
		return 1;
	}
	
	return 0;
}

void move(int dir)
{
	int temp[7] = {0};
	for(int i = 1; i <= 6; i++)
	{
		temp[i] = dice[i];
	}
	
	if(dir == 1)
	{
		dice[3] = temp[6];
		dice[1] = temp[3];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if(dir == 2)
	{
		dice[4] = temp[6];
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[6] = temp[3];
	}
	else if(dir == 3)
	{
		dice[5] = temp[6];
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[6] = temp[2];
	}
	else if(dir == 4)
	{
		dice[2] = temp[6];
		dice[1] = temp[2];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}	
}

void solve(int x, int y)
{
	for(int i = 1; i <= N; i++)
	{
		int dir;
		cin >> dir;
		
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		move(dir);
		//  주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
		if(Map[nx][ny] == 0)
		{
			Map[nx][ny] = dice[6];
		}
		// 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
		else
		{
			dice[6] = Map[nx][ny];
			Map[nx][ny] = 0;
		}
		
		// 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다.
		cout << dice[1] << "\n";
		
		x = nx;
		y = ny;
	}
} 
 
int main(void)
{
//	freopen("B17144_input.txt", "r", stdin);
	
	cin >> row >> col >> startX >> startY >> N;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
		}
	}

	solve(startX, startY);
	
	return 0;
}
