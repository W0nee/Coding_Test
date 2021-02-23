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

typedef struct node
{
	int dir;
	int x;
	int y;
}node;

int row, col;
int N;
vector<node> pos;
node dong;
int ans;

int solve(node pos)
{
	int dir = pos.dir;
	int x = pos.x;
	int y = pos.y;
	
	if((dong.dir == 1 && dir == 2) || (dir == 1 && dong.dir == 2))
	{
		return min(dong.y + y + row,  col-dong.y + col-y + row);
	}
	else if((dong.dir == 3 && dir == 4) || (dir == 3 && dong.dir == 4))
	{
		return min(dong.x + x + col,  row-dong.x + row-x + col);
	}
	else
	{
		return abs(dong.x-x) + abs(dong.y-y);
	}
}

int main(void)
{
//	freopen("B2564_input.txt", "r", stdin);
	
	cin >> col >> row >> N;
	
	for(int i = 1; i <= N+1; i++)
	{
		int dir, d;
		cin >> dir >> d;
		
		if(dir == 1)
		{
			pos.push_back({dir, 0, d});
		}
		else if(dir == 2)
		{
			pos.push_back({dir, row, d});
		}
		else if(dir == 3)
		{
			pos.push_back({dir, d, 0});
		}
		else
		{
			pos.push_back({dir, d, col});
		}
	}
	
	dong.dir = pos[pos.size()-1].dir;
	dong.x = pos[pos.size()-1].x;
	dong.y = pos[pos.size()-1].y;
	
	for(int i = 0; i < pos.size()-1; i++)
	{
		ans += solve(pos[i]);
	}

	cout << ans;
	
	return 0;
}
