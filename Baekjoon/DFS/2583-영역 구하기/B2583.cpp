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

int row, col, K;
int Map[110][110];
int visited[110][110];
int size;
vector<int> result;

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

void DFS(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[nx][ny] == 0 && visited[nx][ny] == 0)
		{
			visited[nx][ny] = 1;
			size++;
			DFS(nx, ny);
		}
	}
}

int main(void)
{
//	freopen("B2583_input.txt", "r", stdin);
	
	cin >> row >> col >> K;
	
	for(int k = 1; k <= K; k++)
	{
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;
		
		for(int x = startX; x < endX; x++)
		{
			for(int y = startY; y < endY; y++)
			{
				Map[y][x] = k;
			}
		}
	}
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(Map[i][j] == 0 && visited[i][j] == 0)
			{
				size = 1;
				visited[i][j] = 1;
				DFS(i, j);
				result.push_back(size);
			}
		}
	}
	
	sort(result.begin(), result.end());
	
	cout << (int)result.size() << endl;
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
