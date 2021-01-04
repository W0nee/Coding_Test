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
int Map[10][10];
int visited[10][10];
int Max;

void color_visit(int x, int y, int n, int shape)
{
	// 가로 
	if(shape == 1)
	{
		for(int j = y; j <= y+n; j++)
		{
			visited[x][j] = 1;
		}	
	}
	// 세로
	else
	{
		for(int i = x; i <= x+n; i++)
		{
			visited[i][y] = 1;
		}
	} 
}

void recover_visit(int x, int y, int n, int shape)
{
	// 가로 
	if(shape == 1)
	{
		for(int j = y; j <= y+n; j++)
		{
			visited[x][j] = 0;
		}	
	}
	// 세로
	else
	{
		for(int i = x; i <= x+n; i++)
		{
			visited[i][y] = 0;
		}
	} 
}

int check_visit()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				return 0;
			}		
		}
	}
	
	return 1;
}

int cal(int x, int y, int n, int shape)
{
	int val = 0;
	
	// 가로 
	if(shape == 1)
	{
		for(int j = y; j <= y+n; j++)
		{
			val += Map[x][j] * pow(10, n-(j-y));
		}
	}
	// 세로 
	else
	{
		for(int i = x; i <= x+n; i++)
		{
			val += Map[i][y] * pow(10, n-(i-x));
		}
	}
	
	return val;
}

int check_possible(int x, int y, int n, int shape)
{
	// 가로 
	if(shape == 1)
	{
		for(int j = y; j <= y+n; j++)
		{
			if(visited[x][j] == 1)
			{
				return 0;
			}
		}
	}
	// 세로 
	else
	{
		for(int i = x; i <= x+n; i++)
		{
			if(visited[i][y] == 1)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void DFS(int x, int y, int sum)
{	
	bool Flag = false;
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				Flag = true;
				x = i;
				y = j;
				break;
			}
		}
		
		if(Flag)
		{
			break;
		}
	}
	
	if(check_visit() == 1)
	{
		Max = max(Max, sum);	
		return;
	}
	
	for(int i = 1; i <= 3; i++)
	{	
		if(y+i <= col && check_possible(x, y, i, 1))
		{
			color_visit(x, y, i, 1);
			DFS(x, y, sum + cal(x, y, i, 1));
			recover_visit(x, y, i, 1);	
		}
		
		if(x+i <= row && check_possible(x, y, i, 2))
		{
			color_visit(x, y, i, 2);
			DFS(x, y, sum + cal(x, y, i, 2));
			recover_visit(x, y, i, 2);		
		}
	}
}

int main(void)
{
//	freopen("B14391_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	if(row == 1 && col == 1)
	{
		cout << Map[1][1];
		
		return 0;
	}
	
	DFS(1, 1, 0);
	
	cout << Max;
	
	return 0;
}
