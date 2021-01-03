#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, L;
int Map[110][110]; 
vector<pair<int, char>> dir;

pair<int, int> head;
deque<pair<int, int>> body;

int d, time;
bool Flag = false;

int dx[4] = {0, 1, 0, -1}; // µ¿³²¼­ºÏ 
int dy[4] = {1, 0, -1, 0}; // µ¿³²¼­ºÏ

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void solve()
{
	int x = head.first;
	int y = head.second;
	int nx = x+dx[d];
	int ny = y+dy[d];
	
	if(safe(nx, ny) == 1)
	{
		if(Map[nx][ny] == 2)
		{
			Map[nx][ny] = 1;
			body.push_back({nx, ny});
		} 
		else if(Map[nx][ny] == 1)
		{
			Flag = true;
			return;
		}
		else
		{
			int tailX = body.front().first;
			int tailY = body.front().second;
			body.pop_front();
			
			Map[nx][ny] = 1;
			Map[tailX][tailY] = 0;	
			body.push_back({nx, ny});
		}
		
		head.first = nx;
		head.second = ny;
	}
	else
	{
		Flag = true;
		return;
	}
}

int main(void)
{
//	freopen("B3190_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int x, y;
		cin >> x >> y;
		
		Map[x][y] = 2; // »ç°ú 
	}
	
	cin >> L;
	
	for(int i = 1; i <= L; i++)
	{
		int t;
		char d;
		cin >> t >> d;
		
		dir.push_back({t, d});
	}
	int dirCnt = 0;
	
	Map[1][1] = 1;
	head.first = 1;
	head.second = 1;
	body.push_front(head);
	
	while(1)
	{
		Flag = false;
		
		if(dir[dirCnt].first == time)
		{
			if(dir[dirCnt].second == 'L')
			{
				d = (d-1) == -1 ? 3 : d-1;
			}			
			else if(dir[dirCnt].second == 'D')
			{
				d = (d+1) == 4 ? 0 : d+1;
			}
			
			dirCnt++;
		}
		
		solve();
		
		time++;
		
		if(Flag)
		{
			cout << time;
			break;
		}
	}
	
	return 0;
}
