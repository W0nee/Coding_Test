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
	int dir;
}node;

int row, col;
char Map[110][110];
int startX, startY;
int findX, findY;
char pipe[7] = {'|', '-', '+', '1', '2', '3', '4'};

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

void check_visit(queue<node> &q, int visited[30][30][4], int nx, int ny, int i)
{
	if(i == 0)
	{
		if((Map[nx][ny] == '-' || Map[nx][ny] == '+') && visited[nx][ny][i] == 0)
		{
			q.push({nx, ny, i});
			visited[nx][ny][i] = 1;
		}
		else if(Map[nx][ny] == '4' && visited[nx][ny][2] == 0)
		{
			q.push({nx, ny, 2});
			visited[nx][ny][2] = 1;
		}
		else if(Map[nx][ny] == '3' && visited[nx][ny][3] == 0)
		{
			q.push({nx, ny, 3});
			visited[nx][ny][3] = 1;
		}
	}
	else if(i == 1)
	{
		if((Map[nx][ny] == '-' || Map[nx][ny] == '+') && visited[nx][ny][i] == 0)
		{
			q.push({nx, ny, i});
			visited[nx][ny][i] = 1;
		}
		else if(Map[nx][ny] == '1' && visited[nx][ny][2] == 0)
		{
			q.push({nx, ny, 2});
			visited[nx][ny][2] = 1;
		}
		else if(Map[nx][ny] == '2' && visited[nx][ny][3] == 0)
		{
			q.push({nx, ny, 3});
			visited[nx][ny][3] = 1;
		}
	}
	else if(i == 2)
	{
		if((Map[nx][ny] == '|' || Map[nx][ny] == '+') && visited[nx][ny][i] == 0)
		{
			q.push({nx, ny, i});
			visited[nx][ny][i] = 1;
		}
		else if(Map[nx][ny] == '2' && visited[nx][ny][0] == 0)
		{
			q.push({nx, ny, 0});
			visited[nx][ny][0] = 1;
		}
		else if(Map[nx][ny] == '3' && visited[nx][ny][1] == 0)
		{
			q.push({nx, ny, 1});
			visited[nx][ny][1] = 1;
		}
	}
	else if(i == 3)
	{
		if((Map[nx][ny] == '|' || Map[nx][ny] == '+') && visited[nx][ny][i] == 0)
		{
			q.push({nx, ny, i});
			visited[nx][ny][i] = 1;
		}
		else if(Map[nx][ny] == '1' && visited[nx][ny][0] == 0)
		{
			q.push({nx, ny, 0});
			visited[nx][ny][0] = 1;
		}
		else if(Map[nx][ny] == '4' && visited[nx][ny][1] == 0)
		{
			q.push({nx, ny, 1});
			visited[nx][ny][1] = 1;
		}
	}
}

void find_empty()
{
	queue<node> q;
	int visited[30][30][4] = {0};
	
	for(int i = 0; i < 4; i++)
	{
		visited[startX][startY][i] = 1;
		
		int nx = startX+dx[i];
		int ny = startY+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		check_visit(q, visited, nx, ny, i);
	}
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int i = q.front().dir;
		q.pop();
		
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[nx][ny] == '.' && visited[nx][ny][i] == 0)
		{
			findX = nx;
			findY = ny;
			return;
		}
		else 
		{
			check_visit(q, visited, nx, ny, i);
		}
	}
}

int check_connect(char pipe)
{
	Map[findX][findY] = pipe;
	
	queue<node> q;
	int visited[30][30][4] = {0};
	
	for(int i = 0; i < 4; i++)
	{
		visited[startX][startY][i] = 1;
		
		int nx = startX+dx[i];
		int ny = startY+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		check_visit(q, visited, nx, ny, i);
	}
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int i = q.front().dir;
		q.pop();
		
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[nx][ny] == 'Z' && visited[nx][ny][i] == 0)
		{
			return 1;
		}
		else 
		{
			check_visit(q, visited, nx, ny, i);
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B2931_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'M')
			{
				startX = i;
				startY = j;
			}
		}
	}
	
	find_empty();
	
	for(int i = 0; i < 7; i++)
	{
		if(check_connect(pipe[i]))
		{
			cout << findX << " " << findY << " " << pipe[i];
			break;
		}
	}
	
	return 0;
}
