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
int x, y, d, g;
int visited[110][110];
int cnt;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve(int x, int y, int d, int g)
{
	vector<int> move;
	move.push_back(d);
	
	for(int i = 1; i <= g; i++)
	{
		vector<int> temp = move;
		
		for(int j = move.size()-1; j >= 0; j--)
		{
			temp.push_back((move[j] + 1) % 4);
		}
		
		move = temp;
	}
	
	visited[x][y] = 1;
	for(int i = 0; i < move.size(); i++)
	{
		int nx = x+dx[move[i]];
		int ny = y+dy[move[i]];
		
		visited[nx][ny] = 1;
		
		x = nx;
		y = ny;
	}
}

int main(void)
{
//	freopen("B15685_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> x >> y >> d >> g;
		
		solve(x, y, d, g);
	}
	
	for(int i = 0; i <= 99; i++)
	{
		for(int j = 0; j <= 99; j++)
		{
			if(visited[i][j] == 1 && visited[i+1][j] == 1 && visited[i][j+1] == 1 && visited[i+1][j+1] == 1)
			{
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
