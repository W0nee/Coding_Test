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

int Map[15][15];
int visited[15][15];

int paper[6] = {0, 5, 5, 5, 5, 5};
int Min = 999999999;

int safe(int x, int y)
{
	if(1 <= x && x <= 10 && 1 <= y && y <= 10)
	{
		return 1;
	}
	
	return 0;
}

int check_possible(int x, int y, int n)
{
	int cnt = 0;
	
	for(int i = x; i < x+n; i++)
	{
		for(int j = y; j < y+n; j++)
		{
			if(Map[i][j] == 1 && visited[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	
	if(cnt == n*n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void make_visit(int x, int y, int n, int val)
{
	for(int i = x; i < x+n; i++)
	{
		for(int j = y; j < y+n; j++)
		{
			visited[i][j] = val;
		}
	}
}

int check_visit()
{
	int cnt = 0;
	
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			if(Map[i][j] == 1 && visited[i][j] == 0)		
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void solve(int x, int y, int ans)
{
	bool Flag = false;
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			if(Map[i][j] ==1 && visited[i][j] == 0)
			{
				Flag = true;
				x = i;
				y = j;
				break;
			}
		}
		
		if(Flag)
		{
			break;
		}
	}
	
	if(check_visit() == 1)
	{
		Min = min(Min, ans);
		return;
	}
	
	for(int i = 1; i <= 5; i++)
	{
//		if(paper[i] >= 1 && check_possible(x, y, i))
		if(paper[i] >= 1 && safe(x+i-1, y+i-1) && check_possible(x, y, i))
		{
			make_visit(x, y, i, 1);
			paper[i]--;
			solve(x, y, ans+1);
			paper[i]++;
			make_visit(x, y, i, 0);
		}	
	}	
}

int main(void)
{
//	freopen("B17136_input.txt", "r", stdin);
	
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve(1, 1, 0);
	
	if(Min == 999999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
