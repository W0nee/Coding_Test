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
//	int n;
	int x;
	int y;
	int dir;
}FISH;

int Map[5][5];
int sharkX, sharkY, sharkDir, eat;
FISH fish[17];
int Max;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

//bool cmp(FISH a, FISH b)
//{
//	if(a.n < b.n)
//	{
//		return true;
//	}
//	
//	return false;
//}

int safe(int x, int y)
{
	if(1 <= x && x <= 4 && 1 <= y && y <= 4)
	{
		return 1;
	}
	
	return 0;
}

int fish_move(int sharkX, int sharkY)
{
//	cout << sharkX << " " << sharkY << endl;
	
	for(int i = 1; i <= 16; i++)
	{
//		cout << i+1 << "------------\n";
//		for(int i = 1; i <= 4; i++)
//		{
//			for(int j = 1; j <= 4; j++)
//			{
//				cout << Map[i][j]+1 << "(" << fish[Map[i][j]].dir << ") ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
	
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;
		
		if(Map[x][y] == 0)
		{
			continue;
		}
		
		for(int k = 0; k < 8; k++)
		{				
			int ndir = (dir + k) % 8;
			int nx = x+dx[ndir];
			int ny = y+dy[ndir];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(!(nx == sharkX && ny == sharkY))
			{	
//				if(i+1 == 13)
//				{
//					cout << "@@ " << dir << "\n";
//				}
				
				fish[Map[x][y]].x = nx;
				fish[Map[x][y]].y = ny;
				fish[Map[x][y]].dir= ndir;
				
				fish[Map[nx][ny]].x = x;
				fish[Map[nx][ny]].y = y;
//				fish[Map[nx][ny]].dir= dir;
				
//				
//				cout << Map[x][y] << " : " << fish[Map[x][y]].dir<< " / " << Map[nx][ny] << " : " << fish[Map[nx][ny]].dir << " " << "\n";
				
				int temp = Map[x][y];
				Map[x][y] = Map[nx][ny];
				Map[nx][ny] = temp;
				
				break;
			}
		}
	}
}

void init()
{
	int n = Map[1][1];
	
	sharkX = fish[n].x;
	sharkY = fish[n].y;
	sharkDir = fish[n].dir;
	
	// ¹°°í±â ¸ÔÀ½ 
	eat += Map[sharkX][sharkY];
	
	// ¹°°í±â Á×À½ 
	Map[sharkX][sharkY] = 0;	
}

void shark_eat(int x, int y, int dir, int eat)
{
	Max = max(Max, eat);
	cout << eat << "\n";
	cout << "shark : " << x << " " << y << " " << dir << "\n";
	
	FISH temp_fish[17];
	int temp_Map[5][5];
	
	for(int i = 1; i <= 16; i++)
	{
		temp_fish[i] = fish[i];
	}
//	
//for(int i = 1; i <= 4; i++)
//	{
//		for(int j = 1; j <= 4; j++)
//		{
//			if(Map[i][j] == -1)
//			{
//				cout << Map[i][j]+1 << "(X) ";
//			}
//			else
//			{
//				cout << Map[i][j]+1 << "(" << fish[Map[i][j]].dir << ") ";	
//			}
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			temp_Map[i][j] = Map[i][j];
		}
	}
	
	fish_move(x, y);
	
//	for(int i = 1; i <= 4; i++)
//	{
//		for(int j = 1; j <= 4; j++)
//		{
//			if(Map[i][j] == -1)
//			{
//				cout << Map[i][j]+1 << "(X) ";
//			}
//			else
//			{
//				cout << Map[i][j]+1 << "(" << fish[Map[i][j]].dir << ") ";	
//			}
//		}
//		cout << "\n";
//	}
//	cout << "\n";
	
	for(int i = 1; i <= 3; i++)
	{
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		
		if(safe(nx, ny) == 0 || Map[nx][ny] == 0)
		{
//			cout << nx << " " << ny << "\n";
			continue;
		}
		
		int temp = Map[nx][ny];
		int ndir = fish[Map[nx][ny]].dir;
		
		Map[nx][ny] = 0;
		shark_eat(nx, ny, ndir, eat+temp);
		Map[nx][ny] = temp;
	}
	
//	fish = temp_fish;
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			Map[i][j] = temp_Map[i][j];
		}
	}
	
	for(int i = 1; i <= 16; i++)
	{
		fish[i] = temp_fish[i];
	}
	
	return;
}

void solve()
{
	init();
	
	shark_eat(sharkX, sharkY, sharkDir, eat);
	
	cout << "@@@@@@@@@@@" << Max;

//	fish_move(sharkX, sharkY);
}

int main(void)
{
//	freopen("B19236_input.txt", "r", stdin);
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			int dir;
			
			cin >> Map[i][j] >> dir;
			
//			Map[i][j]--;
			dir--;
			
			fish[Map[i][j]] = {i, j, dir};
		}
	}
	
//	sort(fish.begin(), fish.end(), cmp);
	
	solve();
	
	return 0;
}
