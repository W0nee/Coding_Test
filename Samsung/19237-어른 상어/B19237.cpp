#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node1
{
	int x;
	int y;
	int dir;
	int dir_order[5][5];
	int live;
}SHARK;

typedef struct node2
{
	int x;
	int y;
	int dir;
}node;

int N, M, smell;
pair<int, int> Map[25][25];
SHARK shark[410];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;	
	}
	else
	{
		return 0;	
	}
}

void renew_shark_move(node new_shark[410])
{
	for(int k = 1; k <= M; k++)
	{
		// 상어 냄새 감소 
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(Map[i][j].first == k)
				{
					Map[i][j].second--;			
					if(Map[i][j].second == 0)
					{
						Map[i][j].first = 0;
					}
				}
			}
		}
		
		if(shark[k].live == 0)
		{
			continue;
		}
		
		int sharkX = shark[k].x;
		int sharkY = shark[k].y;
		int sharkDir = shark[k].dir;
		
		// 새로운 자리에 자신 보다 작은 상어가 이동한 경우 죽음 
		if(1 <= Map[new_shark[k].x][new_shark[k].y].first && Map[new_shark[k].x][new_shark[k].y].first < k)
		{
			shark[k].live = 0; 
			continue;
		}
		
		// 새로운 자리에 상어 위치, 상어 냄새 추가
		shark[k].x = new_shark[k].x;
		shark[k].y = new_shark[k].y;
		shark[k].dir = new_shark[k].dir; 
		
		Map[shark[k].x][shark[k].y].first = k;
		Map[shark[k].x][shark[k].y].second = smell;
	}
}

void shark_move()
{
	node new_shark[410];
	
	for(int k = 1; k <= M; k++)
	{
		if(shark[k].live == 0)
		{
			continue;
		}
		
		int sharkX = shark[k].x;
		int sharkY = shark[k].y;
		int sharkDir = shark[k].dir;
		
		// 가능한 칸 갯수 체크
		vector<node> pos;
		
		for(int i = 1; i <= 4; i++)
		{
			int nx = sharkX + dx[i];
			int ny = sharkY + dy[i];
			int ndir = i;
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			// 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
			if(Map[nx][ny].first == 0)
			{
				pos.push_back({nx, ny, ndir});
			}
		} 
		
		if(pos.size() == 1)
		{
			new_shark[k] = {pos[0].x, pos[0].y, pos[0].dir};
		}
		else if(pos.size() >= 2)
		{
			int x, y, dir;
			bool Flag = false;
			
			for(int i = 1; i <= 4; i++)
			{
				for(int j = 0; j < pos.size(); j++)
				{
					if(shark[k].dir_order[sharkDir][i] == pos[j].dir)
					{
						Flag = true;	
						x = pos[j].x;
						y = pos[j].y;
						dir = pos[j].dir;
						
						break;
					}
				}
				
				if(Flag) break;
			}	
			
			new_shark[k] = {x, y, dir};
		}
		else if(pos.size() == 0)
		{
			vector<node> pos2;
			
			for(int i = 1; i <= 4; i++)
			{
				int nx = sharkX + dx[i];
				int ny = sharkY + dy[i];
				int ndir = i;
				
				if(safe(nx, ny) == 0)
				{
					continue;
				}
				
				// 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다.
				if(Map[nx][ny].first == k)
				{
					pos2.push_back({nx, ny, ndir});
				}
			} 
			
			if(pos2.size() == 1)
			{
				new_shark[k] = {pos2[0].x, pos2[0].y, pos2[0].dir};
			}
			else if(pos2.size() >= 2)
			{
				int x, y, dir;
				bool Flag = false;
				
				for(int i = 1; i <= 4; i++)
				{
					for(int j = 0; j < pos2.size(); j++)
					{
						if(shark[k].dir_order[sharkDir][i] == pos2[j].dir)
						{
							Flag = true;
							x = pos2[j].x;
							y = pos2[j].y;
							dir = pos2[j].dir;
							
							break;
						}
					}
					
					if(Flag) break;
				}	
				
				new_shark[k] = {x, y, dir};
			}
		}
	}
	
	renew_shark_move(new_shark);
}

int check_live_shark()
{
	for(int i = 2; i <= M; i++)
	{
		if(shark[i].live == 1)
		{
			return 0;
		}
	}
	
	return 1;
}

void solve()
{
	int time = 0;
	
	while(time <= 1000)
	{
		if(check_live_shark())
		{
			cout << time;
			return;
		}
		
		shark_move();
		
		time++;
	}

	cout << "-1";	
}

int main(void)
{
//	freopen("B19237_input.txt", "r", stdin);

	cin >> N >> M >> smell;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j].first;		
			
			if(Map[i][j].first >= 1)
			{
				Map[i][j].second = smell;
			
				shark[Map[i][j].first].x = i;	
				shark[Map[i][j].first].y = j;	
			}
		}
	}
	
	for(int k = 1; k <= M; k++)
	{
		cin >> shark[k].dir;
		
		shark[k].live = 1;
	}
	
	for(int k = 1; k <= M; k++)
	{
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				cin >> shark[k].dir_order[i][j];		
			}
		}	
	}
	
	solve();
	
	return 0;
}
