#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int startX;
	int startY;
	int endX;
	int endY;	
	int live;
}node;

typedef struct node2
{
	int d;
	int num;
}node2;

int N, M;
int gas;
int startX, startY;
vector<node> customer;
vector<node2> reserve;
int Map[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool cmp(node2 a, node2 b)
{
	if(a.d < b.d)
	{
		return true;
	}
	else if(a.d == b.d)
	{
		if(customer[a.num].startX < customer[b.num].startX)
		{
			return true;
		}
		else if(customer[a.num].startX == customer[b.num].startX)
		{
			if(customer[a.num].startY < customer[b.num].startY)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int safe(int x, int y)
{
	if(x >= 1 && y >= 1 && x <= N && y <= N) return 1;
	else return 0;
}

int check_customer(int x, int y)
{
	for(int i = 0; i < customer.size(); i++)
	{
		if(customer[i].live == 1)
		{
			if(customer[i].startX == x && customer[i].startY == y)
			{
				return i;
			} 		
		}
	}
	
	return -1;
}

int check_customerLive()
{
	for(int i = 0; i < customer.size(); i++)
	{
		if(customer[i].live == 1)
		{
			return 1;
		}
	}
	
	return 0;
}

void cal_customer(int x, int y)
{
	reserve.clear();
	
	queue<pair<int, int>> q;
	q.push({x, y});
	int visited[25][25] = {0};
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		int check = check_customer(x, y);
		if(check != -1)
		{
			reserve.push_back({visited[x][y]-1, check});
		}
		
		for(int i = 0; i < 4; i++)
		{
			int xpos = x+dx[i];
			int ypos = y+dy[i];
			
			if(safe(xpos, ypos) == 1 && Map[xpos][ypos] == 0 && visited[xpos][ypos] == 0)
			{
				visited[xpos][ypos] = visited[x][y]+1;
				q.push({xpos, ypos});
			}
		}
	}
}

bool cal_arrive(int x, int y, int num)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	int visited[25][25] = {0};
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(x == customer[num].endX && y == customer[num].endY)
		{
			int cost = visited[x][y]-1;
			gas -= cost;
			
			if(gas < 0)
			{
				return false;
			}
			else
			{
				startX = x;
				startY = y;
				gas += 2*cost;
				customer[num].live = 0;
				
				return true;
			}
		}
		
		for(int i = 0; i < 4; i++)
		{
			int xpos = x+dx[i];
			int ypos = y+dy[i];
			
			if(safe(xpos, ypos) == 1 && Map[xpos][ypos] == 0 && visited[xpos][ypos] == 0)
			{
				visited[xpos][ypos] = visited[x][y]+1;
				q.push({xpos, ypos});
			}
		}
	}
	
	return false;
}

int main(void)
{
//	freopen("B19238_input.txt", "r", stdin);
	
	cin >> N >> M >> gas;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cin >> startX >> startY;
	
	for(int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		customer.push_back({a, b, c, d, 1});
	}

//	while(1)
//	{
	for(int i = 0; i < customer.size(); i++)
	{
		cal_customer(startX, startY);
		
//		if(reserve.size() == 0 && check_customerLive() == 1)
		if(reserve.size() == 0)
		{
			cout << -1;
			return 0;
		}
//		else if(reserve.size() == 0 && check_customerLive() == 0)
//		{
//			cout << gas;
//			return 0;
//		}
		
		sort(reserve.begin(), reserve.end(), cmp);
		
		gas -= reserve[0].d;
		
		if(gas <= 0)
		{
			cout << -1;
			return 0;
		}
		
		if(!cal_arrive(customer[reserve[0].num].startX, customer[reserve[0].num].startY, reserve[0].num))
		{
			cout << -1;
			return 0;
		}
	}
	
	cout << gas;
	
	return 0;
}
