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

typedef struct node
{
	int x;
	int y;
	int h;
}node;

int row, col, H;
int Map[110][110][110];
int tomatoCnt;

queue<node> q;
int visited[110][110][110];

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int safe(int x, int y, int h)
{
	if(1 <= x && x <= row && 1 <= y && y <= col && 1 <= h && h <= H)
	{
		return 1;
	}
	
	return 0;
}

void red(int &tomato)
{
	int cnt = q.size();
	tomato += cnt;
	
	while(cnt--)
	{
		int x = q.front().x;
		int y = q.front().y;
		int h = q.front().h;
		q.pop();
		
		for(int i = 0; i < 6; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nh = h+dh[i];
			
			if(safe(nx, ny, nh) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny][nh] == 0 && visited[nx][ny][nh] == 0)
			{
				q.push({nx, ny, nh});
				visited[nx][ny][nh] = 1;
				
				Map[nx][ny][nh] = 1;
			}
		}
	}
}

void solve()
{
	int tomato = 0;
	int day = 0;
	
	while(1)
	{
		red(tomato);
		
		if(q.empty())
		{
			if(tomato == tomatoCnt)
			{
				cout << day;
			}
			else
			{
				cout << "-1";
			}
			
			return;
		}

		day++;
	}
}


int main(void)
{
//	freopen("B7569_input.txt", "r", stdin);
	
	cin >> col >> row >> H;
	
	for(int k = 1; k <= H; k++)
	{
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				cin >> Map[i][j][k];
				
				if(Map[i][j][k] == 1)
				{
					q.push({i, j, k});
					visited[i][j][k] = 1;
				}
				
				if(Map[i][j][k] == 1 || Map[i][j][k] == 0)
				{
					tomatoCnt++;
				}
			}
		}	
	}
	
	solve();
	
	return 0;
}
