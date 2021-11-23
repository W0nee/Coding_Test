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

typedef struct all
{
	int x;
	int y;
	int size;
	int speed;
	int dir;
} all;

typedef struct node
{
	int size;
	int speed;
	int dir;
} node;

int N, M, K;
vector<node> ball[60][60];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void move(int x, int y, vector<all> &newBall)
{
	for(int k = 0; k < ball[x][y].size(); k++)
	{
		int size = ball[x][y][k].size;
		int speed = ball[x][y][k].speed;
		int dir = ball[x][y][k].dir;
		
		int tempSpeed = speed % N;
		
		int nx = (x + dx[dir] * tempSpeed);
		int ny = (y + dy[dir] * tempSpeed);
	
		if(nx <= 0)
		{
			nx += N;
		}
		else if(nx > N)
		{
			nx -= N;
		}
		
		if(ny <= 0)
		{
			ny += N;
		}
		else if(ny > N)
		{
			ny -=N;
		}
		
		newBall.push_back({nx, ny, size, speed, dir});	
	}
}

void check_same()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(ball[i][j].size() >= 2)
			{
				int total_size = 0;
				int total_speed = 0;
				int cnt = ball[i][j].size();
				
				bool all = true;
				bool odd = false;
				
				if(ball[i][j][0].dir % 2 == 1)
				{
					odd = true;
				}
				
				for(int k = 0; k < ball[i][j].size(); k++)
				{
					total_size += ball[i][j][k].size;
					total_speed += ball[i][j][k].speed;
					
					if(odd)
					{
						if(ball[i][j][k].dir % 2 == 0)
						{
							all = false;
						}
					}
					else
					{
						if(ball[i][j][k].dir % 2 == 1)
						{
							all = false;
						}
					}
				}
				
				ball[i][j].clear();
				
				int divide_size = total_size / 5;
				int divide_speed = total_speed / cnt;
				
				if(divide_size <= 0)
				{
					continue;
				}
					
				if(all)
				{			
					ball[i][j].push_back({divide_size, divide_speed, 0});	
					ball[i][j].push_back({divide_size, divide_speed, 2});	
					ball[i][j].push_back({divide_size, divide_speed, 4});	
					ball[i][j].push_back({divide_size, divide_speed, 6});	
				}
				else
				{
					ball[i][j].push_back({divide_size, divide_speed, 1});	
					ball[i][j].push_back({divide_size, divide_speed, 3});	
					ball[i][j].push_back({divide_size, divide_speed, 5});	
					ball[i][j].push_back({divide_size, divide_speed, 7});	
				}
			}
		}
	}
}

void solve()
{
	vector<all> newBall;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(ball[i][j].size() >= 1)
			{
				move(i, j, newBall);
				ball[i][j].clear();
			}
		}
	}
	
	for(int i = 0; i < newBall.size(); i++)
	{
		int x = newBall[i].x;
		int y = newBall[i].y;
		int size = newBall[i].size;
		int speed = newBall[i].speed;
		int dir = newBall[i].dir;
		
		ball[x][y].push_back({size, speed, dir});
	}
	
	check_same();
}

int main(void)
{
//	freopen("B20056_input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	
	for(int i = 1; i <= M; i++)
	{
		int x, y, size, speed, dir;
		cin >> x >> y >> size >> speed >> dir;
		
		ball[x][y].push_back({size, speed, dir});
	}
	
	while(K--)
	{
		solve();
	}
	
	int result = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(ball[i][j].size() >= 1)
			{
				for(int k = 0; k < ball[i][j].size(); k++)
				{
					result += ball[i][j][k].size;	
				}
			}
		}
	}
	
	cout << result;
	
	return 0;
}
