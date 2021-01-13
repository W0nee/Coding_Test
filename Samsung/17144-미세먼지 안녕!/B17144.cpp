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
int T;
int Map[60][60];
vector<pair<int, int>> clean;

int dx[4] = {0, 0, -1, 1}; // µ¿¼­³²ºÏ 
int dy[4] = {1, -1, 0, 0}; // µ¿¼­³²ºÏ 

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

vector<pair<int, int>> mise_init()
{
	vector<pair<int, int>> mise;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] != -1 || Map[i][j] != 0)
			{
				mise.push_back({i, j});
			}
		}
	}
	
	return mise;
}

void mise_spread()
{
	vector<pair<int, int>> mise = mise_init();
	int Temp[60][60] = {0};
	
	for(int k = 0; k < mise.size(); k++)
	{
		int x = mise[k].first;
		int y = mise[k].second;
		
		int val = Map[x][y] / 5;
		int cnt = 0;
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] != -1)
			{
				Temp[nx][ny] += val;
				cnt++;
			}
		}
		
		Map[x][y] = Map[x][y] - (val * cnt) ? Map[x][y] - (val * cnt) : 0;		
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] += Temp[i][j];
		}
	}
}

void clean_spread()
{
	int Temp[60][60] = {0};
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Temp[i][j] = Map[i][j];
		}
	}
	
	for(int k = 0; k < clean.size(); k++)
	{
		int x = clean[k].first;
		int y = clean[k].second;

		Map[x][y+1] = 0;
		
		if(k == 0)
		{	
			for(int i = y+2; i <= col; i++)
			{
				Map[x][i] = Temp[x][i-1];
			}
			
			for(int i = x-1; i >= 1; i--)
			{
				Map[i][col] = Temp[i+1][col];
			}
			
			for(int i = col-1; i >= 1; i--)
			{
				Map[1][i] = Temp[1][i+1];
			}
			
			for(int i = 2; i <= x-1; i++)
			{
				Map[i][1] = Temp[i-1][1];
			}	
		}
		else if(k == 1)
		{
			for(int i = y+2; i <= col; i++)
			{
				Map[x][i] = Temp[x][i-1];
			}
			
			for(int i = x+1; i <= row; i++)
			{
				Map[i][col] = Temp[i-1][col];
			}
			
			for(int i = col-1; i >= 1; i--)
			{
				Map[row][i] = Temp[row][i+1];
			}
			
			for(int i = row-1; i >= x+1; i--)
			{
				Map[i][1] = Temp[i+1][1];
			}
		}
	}
}

void print()
{
	cout << "\n";
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
}

int cal()
{
	int mise_cnt = 0;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] != -1)
			{
				mise_cnt += Map[i][j];
			}
		}
	}
	
	return mise_cnt;
}

void solve()
{
	int time = 0;
	
	while(1)
	{
		mise_spread();
		clean_spread();
		
		time++;
		
		if(time == T)
		{
			cout << cal();
			break;
		}	
	}
} 
 
int main(void)
{
//	freopen("B17144_input.txt", "r", stdin);
	
	cin >> row >> col >> T;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];		
			
			if(Map[i][j] == -1)
			{
				clean.push_back({i, j});
			}
		}
	}
	
	solve();
	
	return 0;
}
