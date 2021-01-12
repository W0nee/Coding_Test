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
		//  �ֻ����� ������ ��, �̵��� ĭ�� ���� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�.
		if(Map[nx][ny] == 0)
		{
			Map[nx][ny] = dice[6];
		}
		// 0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.
		else
		{
			dice[6] = Map[nx][ny];
			Map[nx][ny] = 0;
		}
		
		// �̵��� ������ �ֻ����� �� �鿡 ���� �ִ� ���� ����Ѵ�.
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
