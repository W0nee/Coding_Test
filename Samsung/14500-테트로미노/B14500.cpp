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
int Map[510][510];
int visited[510][510];
int Max;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(0 <= x && x < row && 0 <= y && y < col)
	{
		return 1;
	}
	
	return 0;
}

int tetro5(int x, int y)
{
	int val1 = 0;
	int val2 = 0;
	int val3 = 0;
	int val4 = 0;
	
	if(safe(x+1, y+2) == 1) val1 = Map[x][y] + Map[x][y+1] + Map[x][y+2] + Map[x+1][y+1];
	if(safe(x-1, y+2) == 1) val2 = Map[x][y] + Map[x][y+1] + Map[x][y+2] + Map[x-1][y+1];
	if(safe(x+2, y-1) == 1) val3 = Map[x][y] + Map[x+1][y] + Map[x+2][y] + Map[x+1][y-1];
	if(safe(x+2, y+1) == 1) val4 = Map[x][y] + Map[x+1][y] + Map[x+2][y] + Map[x+1][y+1];
	
	return max({val1, val2, val3, val4});
}

void DFS(int x, int y, int cnt, int sum)
{
	if(cnt == 4)
	{
		Max = max(Max, sum);
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 1 && visited[nx][ny] == 0)
		{
			visited[nx][ny] = 1;
			DFS(nx, ny, cnt+1, sum + Map[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}

void solve()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			visited[i][j] = 1;
			DFS(i, j, 1, Map[i][j]);
			visited[i][j] = 0;
			
			Max = max(Max, tetro5(i, j));
		}
	}	
}

int main(void)
{
//	freopen("B14500_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	cout << Max;
	
	return 0;
}
