#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
char Map[510][510];
int visited[510][510];
bool Find;
int cnt;

int safe(int x, int y)
{
	if(x >= 1 && y >= 1 && x <= row && y <= col) 
	{
		return 1;	
	}
	else
	{
		return 0;	
	} 
}

// 0 : 방문X, 1 : 길, 2 : 길X 
void DFS(int x, int y)
{	
	int xpos, ypos;
	if(Map[x][y] == 'U')
	{
		xpos = x-1;
		ypos = y;
	}
	else if(Map[x][y] == 'R')
	{
		xpos = x;
		ypos = y+1;
	}
	else if(Map[x][y] == 'D')
	{
		xpos = x+1;
		ypos = y;
	}
	else if(Map[x][y] == 'L')
	{
		xpos = x;
		ypos = y-1;
	}
	
	if(safe(xpos, ypos) == 1)
	{
		if(visited[xpos][ypos] == 0)
		{
			visited[xpos][ypos] = 2;
			DFS(xpos, ypos);		
			if(Find)
			{
				visited[xpos][ypos] = 1;
			}
		}
		else if(visited[xpos][ypos] == 1)
		{
			Find = true;
			return;
		}
		else if(visited[xpos][ypos] == 2)
		{
			return;
		}
	}
	else
	{
		Find = true;
		return;
	}
}

int main(void)
{
//	freopen("B17090_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}

	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				Find = false;
				visited[i][j] = 2;
				DFS(i, j);
				if(Find)
				{
					visited[i][j] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	cout << cnt;
	
	return 0;
}
