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

typedef struct shark
{
	int n;
	int x;
	int y;
	int dir;	
}FISH;

int N, M;
pair<int, int> Map[5][5];
vector<FISH> fish;
node shark;
int eat;
int Max;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

bool cmp(FISH a, FISH b)
{
	if(a.n < b.n)
	{
		return true;
	}
	
	return false;
}

int safe(int x, int y)
{
	if(1 <= x && x <= 4 && 1 <= y && y <= 4)
	{
		return 1;
	}
	
	return 0;	
}

vector<FISH> fish_move(int sharkX, int sharkY)
{
	vector<FISH> temp_fish = fish;
	
	for(int i = 0; i < fish.size(); i++)
	{
		int x = fish[i].x;
		int y = fish[i].y;
		
		if(Map[x][y].first == 0)
		{
			continue;
		}
		
		cout << "\n";
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				cout << Map[i][j].first << "(" << Map[i][j].second << ") ";
			}
			cout << "\n";
		}
		
		if(i+1 == 13)
		{
			cout << "--------\n";
			cout << Map[x][y].second << "\n";
			cout << fish[i].dir << " @@ \n";
			cout << "--------\n";
		}
			
		for(int k = 1; k <= 8; k++)
		{
			if(k != 1)
			{
				fish[i].dir++;
			
				if(fish[i].dir == 9)
				{
					fish[i].dir = 1;
				}
			}
			
			cout << "num : " << i+1 << endl;
			cout << k << "  " << fish[i].dir << "\n";
			
//			if(i == 2)
//			{
//				cout << x << " ! " << y << "\n";
//				cout << k << "  " << fish[i].dir << "\n";
//			}
			
			int dir = fish[i].dir;
			Map[x][y].second = dir;
			
			if(i+1 == 13)
			{
				cout << Map[x][y].second << "\n";
				cout << dir << " @@ \n";
			}
			
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			
			// 이동할 수 없는 칸은 상어가 있거나 공간의 경계를 넘는 칸
			if((nx == sharkX && ny == sharkY) || safe(nx, ny) == 0)
			{
				continue;
			} 
			
			// 이동할 수 있는 칸에 물고가 있거나 
			if(Map[nx][ny].first != 0)
			{
				FISH temp = fish[i];
				fish[i] = fish[Map[nx][ny].first-1];
				fish[Map[nx][ny].first-1] = temp;
				
//				cout << fish[i].dir << "\n";
//				cout << fish[Map[nx][ny].first-1].dir << "\n";
				
				
				pair<int, int> temp_map = Map[x][y];
				Map[x][y] = Map[nx][ny];
				Map[nx][ny] = temp_map;
				
				cout << x << " " << y << " @ " << nx << " " << ny << endl;
				
				break;
			}
			// 빈칸인 경우 
			else if(Map[nx][ny].first == 0)
			{
				fish[i].x = nx;
				fish[i].y = ny;
				
				pair<int, int> temp_map = Map[x][y];
				Map[x][y] = Map[nx][ny];
				Map[nx][ny] = temp_map;
				
				break;
			}	
		}
	}
	
	return temp_fish;
}

//void recover_fish(vector<node> temp

//void shark_eat()
//{
//	queue<node> q;
//	int visited[5][5] = {0};
//	
//	q.push({shark.x, shark.y, shark.dir});
////	visited[shark
//
//	while(!q.empty())
//	{
//		int x = q.front().x;
//		int y = q.front().y;
//		int dir = q.front().dir;
//		
//		for(int i = 1; i <= 3; i++)
//		{
//			int nx = x + dx[dir] * i;
//			int ny = y + dy[dir] * i;
//			
//			if(safe(nx, ny) == 0)
//			{
//				continue;
//			}
//			
//			if(Map[nx][ny].first != 0)
//		}
//	}
//	
//}


void shark_eat(int x, int y, int dir, int eat)
{
	Max = max(Max, eat);
	
	pair<int, int> temp_Map[5][5];
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			temp_Map[i][j] = Map[i][j];
		}
	}
	
	vector<FISH> temp_fish = fish_move(x, y);
	
	sort(fish.begin(), fish.end(), cmp);
	
	for(int i = 1; i <= 3; i++)
	{
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		int ndir = Map[nx][ny].second;
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		int temp = Map[nx][ny].first; 
		
		if(Map[nx][ny].first != 0)
		{
			eat += Map[nx][ny].first; // 물고기 먹음 
			Map[nx][ny].first = 0;    // 몰고기 죽음 
			shark_eat(nx, ny, ndir, eat);
			Map[nx][ny].first = temp;
			eat -= Map[nx][ny].first;
		}
	}	
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			Map[i][j] = temp_Map[i][j];
		}
	}
	
	fish = temp_fish;
}

void init()
{
	// 처음 초기화 
	shark.x = 1;
	shark.y = 1;
	shark.dir = Map[1][1].second;
	
	// 물고기 먹기 
	eat += Map[1][1].first;
	
	// 물고기 죽음 
	Map[1][1].first = 0;	
}

void solve()
{
	init();
	
//	shark_eat(shark.x, shark.y, shark.dir, eat);

	fish_move(shark.x, shark.y);
	
//	for(int i = 1; i <= 4; i++)
//	{
//		for(int j = 1; j <= 4; j++)
//		{
//			cout << Map[i][j].first << " ";
//		}
//		cout << "\n";
//	}
	
	cout << Max;
}

int main(void)
{
//	freopen("B19236_input.txt", "r", stdin);
	
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			cin >> Map[i][j].first >> Map[i][j].second;
			
			fish.push_back({Map[i][j].first, i, j, Map[i][j].second});
		}
	}
	
	sort(fish.begin(), fish.end(), cmp);
	
//	for(int i = 0; i < fish.size(); i++)
//	{
//		cout << fish[i].n << "  " << fish[i].x << " " << fish[i].y << endl;
//	}

	solve();

	return 0;
}
