#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int Map[60][60]; // 0: ºóÄ­, 1: º®, 2: ºñÈ°¼º, 3: È°¼º 
int Temp[60][60];
vector<pair<int, int>> virus;
vector<pair<int, int>> choice;
int all_virus_cnt = 0;
int Min = 99999999;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void spread(queue<pair<int, int>> &q, int visited[60][60], int virus_cnt[4])
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
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if((Map[nx][ny] == 0 || Map[nx][ny] == 2) && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				
				virus_cnt[Map[nx][ny]]--;
				virus_cnt[3]++;
			
				Map[nx][ny] = 3;
			}
		}	
	}
}

void solve()
{
	queue<pair<int, int>> q;
	int visited[60][60] = {0};
	int virus_cnt[4] = {0};
	int time = 0;
	
	for(int i = 0; i < choice.size(); i++)
	{
		int x = choice[i].first;
		int y = choice[i].second;
		
		q.push({x, y});
		visited[x][y] = 1;
		Map[x][y] = 3;
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			virus_cnt[Map[i][j]]++;
		}
	}
	
	while(1)
	{		
		if(all_virus_cnt == virus_cnt[2] + virus_cnt[3])
		{
			Min = min(Min, time);	
			return;
		}
		
		spread(q, visited, virus_cnt);
		
		if(q.empty())
		{
			return;
		}
		
		time++;
	}
}

void combination(int idx, int cnt)
{
	if(cnt == M)
	{
		solve();
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				Map[i][j] = Temp[i][j];
			}
		}
		
		return;
	}
	
	for(int i = idx; i < virus.size(); i++)
	{
		choice.push_back({virus[i].first, virus[i].second});
		combination(i+1, cnt+1);
		choice.pop_back();
	}
}

int main(void)
{
//	freopen("B17142_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			Temp[i][j] = Map[i][j];
			
			if(Map[i][j] == 2)
			{
				virus.push_back({i, j});
			}
			
			if(Map[i][j] != 1)
			{
				all_virus_cnt++;
			}
		}
	}

	combination(0, 0);
	
	if(Min == 99999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
