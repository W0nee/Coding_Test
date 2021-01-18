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

int N;
int Map[20][20];
int visited[20];
int ans;

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

int check_daegak(int x, int y)
{
	for(int i = 1; i <= N; i++)
	{
		if(safe(x-i, y-i) == 1)
		{
			if(Map[x-i][y-i] == 1)
			{
				return 0;
			}
		}	
		
		if(safe(x-i, y+i) == 1)
		{
			if(Map[x-i][y+i] == 1)
			{
				return 0;
			}
		}
		
		if(safe(x+i, y-i) == 1)
		{
			if(Map[x+i][y-i] == 1)
			{
				return 0;
			}
		}
		
		if(safe(x+i, y+i) == 1)
		{
			if(Map[x+i][y+i] == 1)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void solve(int row)
{
	if(row == N+1)
	{
		ans++;
		return;
	}
	
	for(int col = 1; col <= N; col++)
	{
		if(visited[col] == 0 && check_daegak(row, col) == 1)
		{
			visited[col] = 1;
			Map[row][col] = 1;
			solve(row+1);	
			Map[row][col] = 0;
			visited[col] = 0;
		}
	}
}

int main(void)
{
//	freopen("B9663_input.txt", "r", stdin);

	cin >> N;

	solve(1);
	
	cout << ans;
	
	return 0;
}
