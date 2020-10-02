#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int row, col, K;
int Map[1010][1010];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void)
{
//	freopen("B10157_input.txt", "r", stdin);

	cin >> col >> row >> K;
	
	int x = 1;
	int y = 1;
	int dir = 0;
	Map[y][x] = 1;
	
	for(int i = 2; i <= K; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			
			if(!(1 <= nx && nx <= col && 1 <= ny && ny <= row) || Map[ny][nx] != 0)
			{
				dir = (dir+1) % 4;
				
				if(j == 4)
				{
					cout << "0";
					return 0;
				}
				
				continue;
			}	
			
			Map[ny][nx] = i;
			x = nx;
			y = ny;
			
			break;
		}
	}
	
	cout << x << " " << y << endl;
	
	return 0;
}
