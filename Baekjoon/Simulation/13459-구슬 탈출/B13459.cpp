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

int row, col;
char Map[15][15];
char MapCopy[15][15];
int visited[15][15];
int candidate[15];

bool ahole = false;
bool bhole = false;
bool success = false;
bool fail = false;

int redx, redy;
int bluex, bluey;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void paste()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = MapCopy[i][j];
		}
	}
}

void solve(int rx, int ry, int bx, int by, int cnt)
{
//	cout << "-- " << rx << " " << ry << " " << bx << " " << by << " " << cnt << " --" << endl;
	
	if(success || fail)
	{
		return;
	}
	else if(cnt == 11)
	{
		fail = true;
		return;
	}
	
	while(1)
	{
		while(1)
		{	
			Map[rx][ry] = '.';
		
			int nrx = rx+dx[candidate[cnt]];
			int nry = ry+dy[candidate[cnt]];			
			
			if(Map[nrx][nry] == '#' || Map[nrx][nry] == 'B')
			{
				Map[rx][ry] = 'R';
				break;
			}
			else if(Map[nrx][nry] == 'O')
			{
				ahole = true;
				break;
			}
			
			rx = nrx;
			ry = nry;
		}
		
		while(1)
		{
			Map[bx][by] = '.';
			
			int nbx = bx+dx[candidate[cnt]];
			int nby = by+dy[candidate[cnt]];
			
			if(Map[nbx][nby] == '#' || Map[nbx][nby] == 'R')
			{
				Map[bx][by] = 'B';
				break;
			}
			else if(Map[nbx][nby] == 'O')
			{
				bhole = true;
				break;
			}
			
			bx = nbx;
			by = nby;
		}
		
		while(1)
		{	
			Map[rx][ry] = '.';
		
			int nrx = rx+dx[candidate[cnt]];
			int nry = ry+dy[candidate[cnt]];			
			
			if(Map[nrx][nry] == '#' || Map[nrx][nry] == 'B')
			{
				Map[rx][ry] = 'R';
				break;
			}
			else if(Map[nrx][nry] == 'O')
			{
				ahole = true;
				break;
			}
			
			rx = nrx;
			ry = nry;
		}
		
		if(ahole == true && bhole == false)
		{
			success = true;
			break;
		}
		else if(ahole == false && bhole == false)
		{
			solve(rx, ry, bx, by, cnt+1);
		}
		else
		{
			fail = true;
			break;
		}
		
		if(fail)
		{
			break;
		}
	}
}

void permutation(int cnt)
{
	if(cnt == 11)
	{
		ahole = false;
		bhole = false;
		success = false;
		fail = false;
		
		paste();
	
//		for(int i = 1; i <= 10; i++)
//		{
//			cout << candidate[i] << " ";
//		}
//		cout << endl;
		
		solve(redx, redy, bluex, bluey, 1);
		
		if(success)
		{
			cout << 1 << endl;
			exit(0);
		}
		else if(fail)
		{
			return;
		}
		
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		if(candidate[cnt-1] == i)
		{
			continue;
		}
		candidate[cnt] = i;
		permutation(cnt+1);
	}
}

int main(void)
{
//	freopen("B13459_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			MapCopy[i][j] = Map[i][j];
			
			if(Map[i][j] == 'R')
			{
				redx = i;
				redy = j;
			}
			else if(Map[i][j] == 'B')
			{
				bluex = i;
				bluey = j;
			}
		}
	}
	
	candidate[0] = 100;
	permutation(1);
	
	cout << 0 << endl;
	
	return 0;
}
