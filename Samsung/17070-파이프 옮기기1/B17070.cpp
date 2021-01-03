#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int garo, sero, daegak;
int Map[20][20];
int visited[20][20];
int cnt;

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void DFS(int x, int y, string shape)
{
	if(safe(x, y) == 0)
	{
		return;
	}
	
	if(x == N && y == N)
	{
		cnt++;	
		return;
	}
	
	if(shape == "garo")
	{
		if(Map[x][y+1] == 0)
		{
			DFS(x, y+1, "garo");	
		}
		if(Map[x+1][y] == 0 && Map[x][y+1] == 0 && Map[x+1][y+1] == 0)
		{
			DFS(x+1, y+1, "daegak");	
		}
	}
	else if(shape == "sero")
	{
		if(Map[x+1][y] == 0)
		{
			DFS(x+1, y, "sero");	
		}
		if(Map[x+1][y] == 0 && Map[x][y+1] == 0 && Map[x+1][y+1] == 0)
		{
			DFS(x+1, y+1, "daegak");	
		}
	}
	else if(shape == "daegak")
	{
		if(Map[x+1][y] == 0)
		{
			DFS(x+1, y, "sero");	
		}
		if(Map[x][y+1] == 0)
		{
			DFS(x, y+1, "garo");	
		}
		if(Map[x+1][y] == 0 && Map[x][y+1] == 0 && Map[x+1][y+1] == 0)
		{
			DFS(x+1, y+1, "daegak");	
		}
	}
}

int main(void)
{
//	freopen("B17070_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	DFS(1, 2, "garo");
	
	cout << cnt;
	
	return 0;
}
