#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int color; // 3: G, 4: R, 7: Flower
}node;

int Map[55][55];
int row, col;
int R, G;
int Max;

vector<int> candidate;
vector<int> feed;
vector<pair<int, int>> possible;
int visitedc[15];
int feedCnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void spread(int MapCopy[55][55], queue<node> &q, int visited[55][55], int &time, int &flower)
{
	int size = q.size();
	
	while(size--)
	{
		int x = q.front().x;
		int y = q.front().y;
		int color = q.front().color;
		q.pop();
		
		if(MapCopy[x][y] == 7)
		{
			continue;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && (MapCopy[nx][ny] == 1 || MapCopy[nx][ny] == 2) && visited[nx][ny] == 0)
			{
				q.push({nx, ny, color});
				MapCopy[nx][ny] = color;
				visited[nx][ny] = time;
			}
			// G to R
			else if(safe(nx, ny) == 1 && MapCopy[x][y] == 3 && MapCopy[nx][ny] == 4 && visited[nx][ny] == time)
			{
				MapCopy[nx][ny] = 7;
				flower++;
		 	}
		 	// R to G
		 	else if(safe(nx, ny) == 1 && MapCopy[x][y] == 4 && MapCopy[nx][ny] == 3 && visited[nx][ny] == time)
		 	{
		 		MapCopy[nx][ny] = 7;
		 		flower++;
 			}
		}
	}
}

void simulation()
{
	int MapCopy[55][55];
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			MapCopy[i][j] = Map[i][j];
		}
	}
	
	queue<node> q;
	int visited[55][55] = {0};
	int time = 1;
	int flower = 0;
	
	for(int i = 0; i < candidate.size(); i++)
	{
		int x = possible[i].first;
		int y = possible[i].second;
		int color = candidate[i];
		
		if(color == 3 || color == 4)
		{
			q.push({x, y, color});
			MapCopy[x][y] = color;
			visited[x][y] = time;	
		}
	}
	
	while(!q.empty())
	{
		spread(MapCopy, q, visited, ++time, flower);
		Max = max(Max, flower);
	}	
}

void DFS(int cnt)
{
	if(cnt == feedCnt)
	{
		simulation();
		return;
	}
	
	int used[10] = {0};
	
	// 3: G, 4: R, 5: X
	for(int i = 0; i < feed.size(); i++)
	{
		if(visitedc[i] == 0 && used[feed[i]] == 0)
		{
			used[feed[i]] = 1;
			visitedc[i] = 1;
			candidate.push_back(feed[i]);
			DFS(cnt+1);
			candidate.pop_back();	
			visitedc[i] = 0;
		}
	}
}

int main(void)
{
//	freopen("B18809_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> row >> col >> G >> R;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 2)
			{
				feedCnt++;
				possible.push_back({i, j});
			}
		}
	}

	for(int i = 1; i <= G; i++)
	{
		feed.push_back(3);
	}
	for(int i = 1; i <= R; i++)
	{
		feed.push_back(4);
	}
	for(int i = 1; i <= feedCnt-R-G; i++)
	{
		feed.push_back(5);
	}
	
	DFS(0);
	
	cout << Max;
	
	return 0;
}
