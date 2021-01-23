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
	int startX;
	int startY;
	int arriveX;
	int arriveY;
	int d;
}node;

int N;
int M, fuel;
int Map[30][30];
deque<node> customer;
int customer_check[500];
int bX, bY;
int cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool cmp(node a, node b)
{
	if(a.startX < b.startX)
	{
		return true;
	}
	else if(a.startX == b.startX)
	{
		if(a.startY < b.startY)
		{
			return true;
		}
		
		return false;
	}
	else
	{
		return false;
	}
}

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

vector<node> check_min_distance()
{
	queue<pair<int, int>> q;
	int visited[30][30] = {0};
	int Min = 99999999;
	vector<node> list;
	
	q.push({bX, bY});
	visited[bX][bY] = 1;
	
	if(Map[bX][bY] >= 0)
	{
		Min = min(Min, visited[bX][bY]);
	}
	
	while(!q.empty())
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
			
			if(Map[nx][ny] == -1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
			else if(Map[nx][ny] >= 0 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				Min = min(Min, visited[nx][ny]);
			}
		}
	}
	
	for(int i = 0; i < customer.size(); i++)
	{
		if(customer_check[i] != 0)
		{
			continue;
		}
		
		int x = customer[i].startX;
		int y = customer[i].startY;
		
		if(Min == visited[x][y])
		{
			customer[i].d = Min-1; 
			list.push_back(customer[i]);
		}
	}
	
	sort(list.begin(), list.end(), cmp);
	
//	for(int i = 0; i < list.size(); i++)
//	{
//		cout << list[i].startX << "  " << list[i].startY << "  " << list[i].d << "\n";
//	}
	
	return list;
}

int check_arrive_distance(int startX, int startY, int arriveX, int arriveY)
{
	queue<pair<int, int>> q;
	int visited[30][30] = {0};
	
	q.push({startX, startY});
	visited[startX][startY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(x == arriveX && y == arriveY)
		{
			return visited[x][y] - 1;	
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] >= -1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	
	return 0;
}

void solve()
{
	while(1)
	{
//		cout << "-----------------------------\n";
		
		vector<node> list = check_min_distance();
		
		if(list.size() == 0)
		{
			cout << "-1";
			break;
		}
	
		int startX = list[0].startX;
		int startY = list[0].startY;
		int arriveX = list[0].arriveX;
		int arriveY = list[0].arriveY;
		int d = list[0].d;
		
		
//		cout << "taxi : " << bX << " " << bY << "\n";
//		cout << "customer : " << startX << " " << startY << "  /  " << arriveX << " " << arriveY << "\n";
		
		fuel -= d;
		
		if(fuel < 0)
		{
			cout << "-1";
			break;
		}
		
//		cout << "fuel1 : " << fuel << "\n";
		
		int val = check_arrive_distance(startX, startY, arriveX, arriveY);
		
//		cout << "val : " << val << "\n";
		
		if(val == 0)
		{
			cout << "-1";
			break;
		}
		else
		{
			cnt++;
		}
		
		fuel += val;
		
//		cout << "fuel2 : " << fuel << "\n";
//		cout << "cnt " << cnt << "\n";
		
		if(cnt == M)
		{
			cout << fuel;
			break;
		}
		
		customer_check[Map[startX][startY]] = 1;
		Map[startX][startY] = -1;
		
		bX = arriveX;
		bY = arriveY;	
	}
}

int main(void)
{
//	freopen("B19238_input.txt", "r", stdin);
	
	cin >> N >> M >> fuel;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 1)
			{
				Map[i][j] = -2;
			}
			else if(Map[i][j] == 0)
			{
				Map[i][j] = -1;
			}
		}
	}
	
	cin >> bX >> bY;
	
	for(int i = 0; i < M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		Map[a][b] = i;
		customer.push_back({a, b, c, d, 0});
	}
	
	solve();
	
	return 0;
}
