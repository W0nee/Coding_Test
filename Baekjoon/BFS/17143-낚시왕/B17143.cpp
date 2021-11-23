#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef struct all {
	int x;
	int y;
	int speed;
	int dir;
	int size;
} all;

typedef struct node {
	int speed;
	int dir;
	int size;
} node;

int row, col, num;
int king;
int result;

vector<node> shark[110][110];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void move(int x, int y, vector<all> &newShark)
{
	int speed = shark[x][y][0].speed;
	int dir = shark[x][y][0].dir;
	int size = shark[x][y][0].size;
	
	int cnt;
	if(dir == 1 || dir == 2)
	{
		cnt = speed % ((row-1) * 2);
	}
	else
	{
		cnt = speed % ((col-1) * 2);
	}
	
	while(cnt--)
	{
		if(dir == 1)
		{
			if(x == 1)
			{
				dir = 2;
			}
		}
		else if(dir == 2)
		{
			if(x == row)
			{
				dir = 1;
			}
		}
		else if(dir == 3)
		{
			if(y == col)
			{
				dir = 4;
			}
		}
		else if(dir == 4)
		{
			if(y == 1)
			{
				dir = 3;
			}
		}
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];	
		
		x = nx;
		y = ny;
	}

	newShark.push_back({x, y, speed, dir, size});
}

void check_same()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j<= col; j++)
		{
			if(shark[i][j].size() >= 2)
			{
				int Max = 0;
				node maxShark;
				
				for(int k = 0; k < shark[i][j].size(); k++)
				{
					if(Max < shark[i][j][k].size)
					{
						Max = shark[i][j][k].size;
						maxShark = {shark[i][j][k].speed, shark[i][j][k].dir, shark[i][j][k].size};
					}
				}
				
				shark[i][j].clear();
				shark[i][j].push_back(maxShark);
			}
		}
	}
}

void time()
{
	vector<all> newShark;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(shark[i][j].size() >= 1)
			{
				move(i, j, newShark);
				shark[i][j].clear();
			}	
		}
	}
	
	for(int i = 0; i < newShark.size(); i++)
	{
		int x = newShark[i].x;
		int y = newShark[i].y;
		int speed = newShark[i].speed;
		int dir = newShark[i].dir;
		int size = newShark[i].size;
		
		shark[x][y].push_back({speed, dir, size});
	}
}

void fishing()
{
	king++;
	
	for(int i = 1; i <= row; i++)
	{
		if(shark[i][king].size() >= 1)
		{
			result += shark[i][king][0].size;
			shark[i][king].clear();
			
			break;
		}	
	}	
}

int main(void)
{
//	freopen("B17143_input.txt", "r", stdin);

	cin >> row >> col >> num;
	
	for(int i = 1; i <= num; i++)
	{
		int x, y, speed, dir, size;
		cin >> x >> y >> speed >> dir >> size;
		
		shark[x][y].push_back({speed, dir, size});
	}
	
	while(king != col)
	{
		fishing();
		
		time();
		
		check_same();	
	}
	
	cout << result << endl;
	
	return 0;
}
