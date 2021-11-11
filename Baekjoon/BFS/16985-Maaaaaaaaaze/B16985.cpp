#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef struct node
{
	int x;
	int y;
	int z;
}node;

int row, col, h;
int Map[10][10][10];
int New_Map[10][10][10];
int Min = INF;

int rotate_count[10];
int map_order[10];
int check[10];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int safe(int x, int y, int z)
{
	if(1 <= x && x <= 5 && 1 <= y && y <= 5 && 1 <= z && z <= 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void rotate(int k, int cnt)
{	
	int Temp_Map[10][10][10]; 
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			Temp_Map[i][j][k] = Map[i][j][k];		
		}
	}

	while(cnt--)
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				New_Map[j][5+1-i][k] = Temp_Map[i][j][k];		
			}
		}	
		
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				Temp_Map[i][j][k] = New_Map[i][j][k];		
			}
		}	
	}
}

void BFS()
{
	queue<node> q;
	int visited[10][10][10] = {0};
	
	q.push({1, 1, 1});
	visited[1][1][1] = 1;	
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		if(x == 5 && y == 5 && z == 5)
		{
			Min = min(Min, visited[x][y][z]-1);
			return;
		}
		
		for(int i = 0; i < 6; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			
			if(safe(nx, ny, nz) == 0)
			{
				continue;
			}
			
			if(New_Map[nx][ny][nz] == 1 && visited[nx][ny][nz] == 0)
			{
				q.push({nx, ny, nz});
				visited[nx][ny][nz] = visited[x][y][z] + 1;
			}
		}
	}
}

void remake()
{	
	// 회전 
	for(int k = 1; k <= 5; k++)
	{
		rotate(k, rotate_count[k]);
	}
	
	// 판 순서 
	int Temp_Map[10][10][10]; 
	
	for(int k = 1; k <= 5; k++)
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				Temp_Map[i][j][k] = New_Map[i][j][k];		
			}
		}	
	}
	
	
	for(int k = 1; k <= 5; k++)
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				New_Map[i][j][map_order[k]] = Temp_Map[i][j][k];
			}
		}	
		
		cout << "* : " << map_order[k] << " " << k << endl;
	}	
}

void map_check(int cnt)
{
	if(cnt == 6)
	{		
		remake();
		
		if(New_Map[1][1][1] == 1 && New_Map[5][5][5] == 1)
		{
			BFS();	
			
			cout << "==========================\n";
			for(int i = 1; i <= 5; i++)
			{
				cout << rotate_count[i] << " ";
			}
			cout << endl;
			for(int i = 1; i <= 5; i++)
			{
				cout << map_order[i] << " ";
			}
			cout << Min << endl;
			
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
			
			for(int k = 1; k <= 5; k++)
			{
				for(int i = 1; i <= 5; i++)
				{
					for(int j = 1; j <= 5; j++)
					{
						cout << New_Map[i][j][k] << " ";		
					}
					cout << endl;
				}	
				cout << endl;
			}
			
			cout << "==========================\n";
		}
		
		return;
	}
	
	for(int i = 1; i <= 5; i++)
	{
		if(check[i] == 0)
		{
			check[i] = 1;
			map_order[cnt] = i;
			map_check(cnt+1);
			check[i] = 0;
		}
	}
}

void rotate_check(int cnt)
{
	if(cnt == 6)
	{
		map_check(1);
		return;
	}
	
	for(int i = 0; i <= 3; i++)
	{
		rotate_count[cnt] = i;
		rotate_check(cnt+1);
	}
}

int main(void)
{
//	freopen("B16985_input.txt", "r", stdin);

	for(int k = 1; k <= 5; k++)
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				cin >> Map[i][j][k];	
			}
		}	
	}	

	rotate_check(1);
	
	if(Min == INF)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}	
	
	return 0;
}
