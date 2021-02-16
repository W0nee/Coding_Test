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
char Map[15][15];
int redX, redY;
int blueX, blueY;
bool Flag = false;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void marble_move(int color, int dir, int &redHole, int &blueHole)
{
	if(color == 1)
	{
		while(1)
		{
			int nx = redX + dx[dir];
			int ny = redY + dy[dir];
			
			if(safe(nx, ny) == 0)
			{
				break;
			}
			
			if(Map[nx][ny] == '.')
			{
				redX = nx;
				redY = ny;
			}
			else if(Map[nx][ny] == 'O')
			{
				redHole = 1;
				break;
			}
			else
			{
				break;
			}
		}	
	}
	else
	{
		while(1)
		{
			int nx = blueX + dx[dir];
			int ny = blueY + dy[dir];
			
			if(safe(nx, ny) == 0)
			{
				break;
			}
			
			if(Map[nx][ny] == '.')
			{
				blueX = nx;
				blueY = ny;
			}
			else if(Map[nx][ny] == 'O')
			{
				blueHole = 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
}

void solve(int order, int dir, int &redHole, int &blueHole)
{
	if(order == 1)
	{
		Map[redX][redY] = '.';
		marble_move(1, dir, redHole, blueHole);
		if(redHole == 0) Map[redX][redY] = 'R';
		
		Map[blueX][blueY] = '.';
		marble_move(2, dir, redHole, blueHole);
		if(blueHole == 0) Map[blueX][blueY] = 'B';
	}
	else
	{
		Map[blueX][blueY] = '.';
		marble_move(2, dir, redHole, blueHole);
		if(blueHole == 0) Map[blueX][blueY] = 'B';
		
		Map[redX][redY] = '.';
		marble_move(1, dir, redHole, blueHole);
		if(redHole == 0) Map[redX][redY] = 'R';
	}
}

int check_move(int dir)
{
	int redHole = 0;
	int blueHole = 0;
	
	if(dir == 0)
	{
		if(redY < blueY)
		{
			solve(1, dir, redHole, blueHole);
		}
		else
		{
			solve(2, dir, redHole, blueHole);
		}
	}
	else if(dir == 1)
	{
		if(redY > blueY)
		{
			solve(1, dir, redHole, blueHole);
		}
		else
		{
			solve(2, dir, redHole, blueHole);
		}
	}
	else if(dir == 2)
	{
		if(redX < blueX)
		{
			solve(1, dir, redHole, blueHole);
		}
		else
		{
			solve(2, dir, redHole, blueHole);
		}
	}
	else if(dir == 3)
	{
		if(redX > blueX)
		{
			solve(1, dir, redHole, blueHole);
		}
		else
		{
			solve(2, dir, redHole, blueHole);
		}
	}
	
	if(redHole == 1 && blueHole == 0)
	{
		return 1;
	}
	else if(redHole == 0 && blueHole == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void DFS(int cnt)
{
	if(cnt >= 10)
	{
		return;
	}
	
	char Temp_Map[15][15];
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Temp_Map[i][j] = Map[i][j];
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		int temp_redX = redX;
		int temp_redY = redY;
		int temp_blueX = blueX;
		int temp_blueY = blueY;
		
		int val = check_move(i);
		
		if(val == 1)
		{
			Flag = true;
			return;
		}
		else if(val == 0)
		{
			DFS(cnt+1);
		}

		if(Flag)
		{
			return;
		}
		
		redX = temp_redX;
		redY = temp_redY;
		blueX = temp_blueX;
		blueY = temp_blueY;
		
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				Map[i][j] = Temp_Map[i][j];
			}
		}
	}
}

int main(void)
{
//	freopen("B13459_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'R')
			{
				redX = i;
				redY = j;
			}
			else if(Map[i][j] == 'B')
			{
				blueX = i;
				blueY = j;
			}
		}
	}
	
	DFS(0);
	
	if(Flag)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	return 0;
}
