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

int row, col, D;
int Map[20][20];
int tempMap[20][20];
int visited[20][20];
vector<int> archer;
int Max;

typedef struct node
{
	int x;
	int y;
	int val;
}node;

bool cmp(node a, node b)
{
	if(a.val < b.val)
	{
		return true;
	}
	else if(a.val == b.val)
	{
		if(a.y < b.y)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

void copy()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			Map[i][j] = tempMap[i][j];
		}
	}
}

int check_enemy()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(Map[i][j] == 1)
			{
				return 1;
			}
		}
	}
	
	return 0;
}

void move()
{
	for(int i = row-1; i >= 0; i--)
	{
		for(int j = 0; j < col; j++)
		{
			Map[i+1][j] = Map[i][j];
		}
	}
	
	for(int j = 0; j < col; j++)
	{
		Map[0][j] = 0;
	}
}

void print()
{
	cout << "--move Map--\n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
}

int solve()
{	
	vector<pair<int, int>> kill;
	int killCnt = 0;

	while(check_enemy() == 1)
	{
		vector<node> enemy[3];
	
		for(int k = 0; k < 3; k++)
		{		
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					if(Map[i][j] == 1)
					{
						int x = row;
						int y = archer[k];
						int val = abs(x-i) + abs(y-j);
						
						if(val <= D)
						{
							enemy[k].push_back({i, j, val});	
						}
					}
				}
			}	
			
			sort(enemy[k].begin(), enemy[k].end(), cmp);
		}
		
		map<pair<int, int>, int> visited;
		for(int i = 0; i < 3; i++)
		{
			if(enemy[i].size() >= 1)
			{
				int x = enemy[i][0].x;
				int y = enemy[i][0].y;
				
				if(visited[{x, y}] == 0)
				{
					visited[{x, y}] = 1;
					Map[x][y] = 0;
					killCnt++;
				}	
			}
		}
		
		move();	
	}
	
	return killCnt;
}

void combination(int idx, int cnt)
{
	if(cnt == 3)
	{
		Max = max(Max, solve());		
		copy();
		
		return;
	}	
	
	for(int i = idx; i < col; i++)
	{
		archer.push_back(i);
		combination(i+1, cnt+1);
		archer.pop_back();
	}
}

int main(void)
{
//	freopen("B17070_input.txt", "r", stdin);
	
	cin >> row >> col >> D;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
			tempMap[i][j] = Map[i][j];
		}
	}
	
	combination(0, 0);
	
	cout << Max;
	
	return 0;
}
