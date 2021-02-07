#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
char Map[15][15];
int redX, redY;
int blueX, blueY;
int Min = 99999999;
bool Flag = false;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x & x <= row && 1 <= y && y <= col)
	{
		return 1;	
	}

	return 0;	
}

void move_color(int &redHole, int &blueHole, int dir, int color)
{
	if(color == 1)
	{
		while(1)
		{
			int nx = redX + dx[dir];
			int ny = redY + dy[dir];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == '.')
			{
				redX = nx;
				redY = ny;
			}				
			else if(safe(nx, ny) == 1 && Map[nx][ny] == 'O')
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
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == '.')
			{
				blueX = nx;
				blueY = ny;
			}				
			else if(safe(nx, ny) == 1 && Map[nx][ny] == 'O')
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

int move(int dir)
{
	int redHole = 0;
	int blueHole = 0;
	
	// 왼쪽 기울이기 
	if(dir == 0)
	{
		if(redY < blueY)
		{
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
			
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
		} 
		else
		{
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
			
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
		}
	}
	// 오른쪽 기울이기 
	else if(dir == 1)
	{
		if(redY < blueY)
		{
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
			
			Map[redX][redY] = '.';
			move_color(redHole, blueHole,dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
		}
		else
		{
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
			
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
		}
	}
	// 위쪽 기울이기 
	else if(dir == 2)
	{
		if(redX < blueX)
		{
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
			
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
		}
		else
		{
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
			
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
		}
	}
	// 아래쪽 기울이기 
	else if(dir == 3)
	{
		if(redX < blueX)
		{
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
			
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
		}
		else
		{
			Map[redX][redY] = '.';
			move_color(redHole, blueHole, dir, 1);
			if(redHole == 0) Map[redX][redY] = 'R';
			
			Map[blueX][blueY] = '.';
			move_color(redHole, blueHole, dir, 0);
			if(blueHole == 0) Map[blueX][blueY] = 'B';
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

void copy(char temp_Map[15][15])
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			temp_Map[i][j] = Map[i][j];		
		}
	}
}

void paste(char temp_Map[15][15])
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = temp_Map[i][j];		
		}
	}
}

void DFS(int ans)
{
	if(ans >= 10)
	{
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		char temp_Map[15][15];
		int temp_redX = redX;
		int temp_redY = redY;
		int temp_blueX = blueX;
		int temp_blueY = blueY;
		copy(temp_Map);
		
		int val = move(i);
		
//		cout << "\n" << i << " " << ans << endl;
//		for(int i = 1; i <= row; i++)
//		{
//			for(int j = 1; j <= col; j++)
//			{
//				cout << Map[i][j] << " ";
//			}
//			cout << "\n";
//		}
		
		if(val == 1)
		{
			Min = min(Min, ans+1);
			
			paste(temp_Map);
			redX = temp_redX;
			redY = temp_redY;
			blueX = temp_blueX;
			blueY = temp_blueY;
			
			return;
		}
		else if(val == 0)
		{
			DFS(ans+1);
			
			paste(temp_Map);
			redX = temp_redX;
			redY = temp_redY;
			blueX = temp_blueX;
			blueY = temp_blueY;
		}
		else if(val == -1)
		{
			paste(temp_Map);
			redX = temp_redX;
			redY = temp_redY;
			blueX = temp_blueX;
			blueY = temp_blueY;
			
			continue;
		}
	}	
}

int main(void)
{
//	freopen("B13460_input.txt", "r", stdin);

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
	
	if(Min == 99999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
