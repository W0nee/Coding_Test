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
char Map[1550][1550];

vector<pair<int, int>> temp;
int visited[1550][1550];
int swanX, swanY;

queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

bool meet()
{
	queue<pair<int, int>> q;
	map<pair<int, int>, int> check;

	for(int i = 0; i < temp.size(); i++)
	{
		int x = temp[i].first;
		int y = temp[i].second;
		
		q.push({x, y});
		visited[x][y] = 1;
	}	
	
	temp.clear();
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1)
			{
				if(Map[nx][ny] == '.' && visited[nx][ny] == 0)
				{
					q.push({nx, ny});
					visited[nx][ny] = 1;
				}
				else if(Map[nx][ny] == 'L' && visited[nx][ny] == 0)
				{
					return true;
				}
				else if(Map[nx][ny] == 'X' && check[{x, y}] == 0)
				{
					temp.push_back({x, y});
					check[{x, y}] = 1;
				}
			}
		}
	}
	
	return false;
}

void melt(queue<pair<int, int>> &q)
{
	int cnt = q.size();
	
	while(cnt--)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1)
			{
				if(Map[nx][ny] == 'X')
				{
					q.push({nx, ny});
					Map[nx][ny] = '.';
				}
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

void solve()
{
	int day = 0;
	
	while(1)
	{
		if(meet())
		{
			cout << day;
			break;
		}
		
		melt(q);
		
//		print();
		
		day++;
	}
}

int main(void)
{
//	freopen("B3197_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)	
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			// 백조가 물 위에 떠있다. 
			if(Map[i][j] == '.' || Map[i][j] == 'L')
			{
				q.push({i, j});
			}
			
			if(Map[i][j] == 'L')
			{
				swanX = i;
				swanY = j;
			}
		}
	}

	temp.push_back({swanX, swanY});
	
	solve();
	
	return 0;
}
