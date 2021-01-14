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

int N;
int Map[25][25];
int visited[25][25];
int Min = 999999999;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y, int d1, int d2)
{
	if(1 <= x && x+d1+d2 <= N && 1 <= y-d1 && y+d2 <= N)
	{
		return 1;
	}
	
	return 0;
}

void color1234(int x, int y, int d1, int d2)
{
	for(int i = 1; i < x+d1; i++)
	{
		for(int j = 1; j <= y; j++)
		{
			if(visited[i][j] == 5)
			{
				break;
			}
			
			visited[i][j] = 1;
		}
	}
	
	for(int i = 1; i <= x+d2; i++)
	{
		for(int j = N; j > y; j--)
		{
			if(visited[i][j] == 5)
			{
				break;
			}
			
			visited[i][j] = 2;
		}
	}	
	
	for(int i = x+d1; i <= N; i++)
	{
		for(int j = 1; j < y-d1+d2; j++)
		{
			if(visited[i][j] == 5)
			{
				break;
			}
			
			visited[i][j] = 3;
		}
	}

	for(int i = x+d2+1; i <= N; i++)
	{
		for(int j = N; j >= y-d1+d2; j--)
		{
			if(visited[i][j] == 5)
			{
				break;
			}
			
			visited[i][j] = 4;
		}
	}
}

void color5(int x, int y, int d1, int d2)
{
	for(int i = 0; i <= d1; i++)
	{
		int nx = x + i;
		int ny = y - i;
		visited[nx][ny] = 5;
		
		nx = x + d2 + i;
		ny = y + d2 - i;
		visited[nx][ny] = 5;
	}
	
	for(int i = 0; i <= d2; i++)
	{
		int nx = x + i;
		int ny = y + i;
		visited[nx][ny] = 5;
		
		nx = x + d1 + i;
		ny = y - d1 + i;
		visited[nx][ny] = 5;
	}
}

void print()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";	
}

int cal()
{
	int sum[6] = {0};
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(visited[i][j] == 0 || visited[i][j] == 5)
			{
				sum[5] += Map[i][j];	
			}
			else
			{
				sum[visited[i][j]] += Map[i][j];
			}
		}
	}
	
	int Max = max({sum[1], sum[2], sum[3], sum[4], sum[5]});
	int Min = min({sum[1], sum[2], sum[3], sum[4], sum[5]});
	
	return Max - Min;
}

void solve()
{
	for(int x = 1; x <= N; x++)
	{
		for(int y = 1; y <= N; y++)
		{
			for(int d1 = 1; d1 <= N; d1++)
			{
				for(int d2 = 1; d2 <= N; d2++)
				{
					if(safe(x, y, d1, d2) == 1)
					{
						memset(visited, 0, sizeof(visited));
						
						color5(x, y, d1, d2);
						color1234(x, y, d1, d2);
						
						Min = min(Min, cal());
					}
				}
			}
		}
	}
	
	cout << Min;
}

int main(void)
{
//	freopen("B17779_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	return 0;
}
