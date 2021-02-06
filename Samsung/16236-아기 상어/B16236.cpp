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
	int d; // fish : distance, shark : eaten count 
	int size;
}node;

int N;
int Map[25][25];
bool Flag = false;
int time;

node shark;
deque<node> fish;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool cmp(node a, node b)
{
	if(a.d < b.d)
	{
		return true;
	}
	else if(a.d == b.d)
	{
		if(a.x < b.x)
		{
			return true;
		}
		else if(a.x == b.x)
		{
			if(a.y < b.y)
			{
				return true;
			}
			
			return false;
		}
		
		return false;
	}
	
	return false;	
}

vector<node> cal_distance(int x, int y)
{
	queue<pair<int, int>> q;
	int visited[25][25] = {0};
	vector<node> eat;
	
	q.push({x, y});
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(1 <= Map[x][y] && Map[x][y] <= 6 && Map[x][y] < shark.size)
		{
			eat.push_back({x, y, visited[x][y]-1, Map[x][y]});
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(!(1 <= nx && nx <= N && 1 <= ny && ny <= N))
			{
				continue;
			}
			
			if(visited[nx][ny] == 0 && Map[nx][ny] <= shark.size)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
		 } 
	}
	
	return eat;
}

void print()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";	
}

void DFS(int x, int y)
{
	if(Flag)
	{
		return;
	}
	
	vector<node> eat = cal_distance(shark.x, shark.y);
	
	sort(eat.begin(), eat.end(), cmp);
	
//	cout << "\n----stage---\n";
//	cout << "----shark size : " << shark.size << "----\n";
//	cout << "----shark eaten : " << shark.d << "----\n";
//	cout << "time : " << time << "\n";
//	print();
//	for(int i = 0; i < eat.size(); i++)
//	{
//		cout << "distance : " << eat[i].d << "  [x, y, z] : " << eat[i].x << " " << eat[i].y << " " << eat[i].size << "\n";
//	}
	
	if(eat.size() == 0)
	{
		Flag = true;
		return;
	}
	else
	{
		int nx = eat[0].x;
		int ny = eat[0].y;
		time += eat[0].d;
		
		shark.x = nx;
		shark.y = ny;
		shark.d += 1;
		if(shark.d == shark.size)
		{
			shark.size += 1;	
			shark.d = 0;
		}
		
		Map[x][y] = 0;
		Map[nx][ny] = 9;
		
		DFS(nx, ny);
	}
}

int main(void)
{
//	freopen("B16236_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];		
			
			if(1 <= Map[i][j] && Map[i][j] <= 6)
			{
				fish.push_back({i, j, 0, Map[i][j]});
			}
			else if(Map[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				shark.d = 0;
				shark.size = 2;
			}
		}
	}
	
	DFS(shark.x, shark.y);
	
	cout << time;
	
	return 0;
}
