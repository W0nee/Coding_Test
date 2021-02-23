#include <stdio.h>
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

int T;
string control;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
//	freopen("B8911_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> T;
	
	while(T--)
	{
		cin >> control;
		
		int x = 500;
		int y = 500;
		int dir = 0;
		int minX = x;
		int minY = y;
		int maxX = x;
		int maxY = y;
		
		for(int i = 0; i < control.size(); i++)
		{
			if(control[i] == 'L')
			{
				dir = dir-1 == -1 ? 3 : dir-1;
			}
			else if(control[i] == 'R')
			{
				dir = (dir+1) % 4;
			}
			else if(control[i] == 'F')
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				x = nx;
				y = ny;
			}
			else if(control[i] == 'B')
			{
				int nx = x - dx[dir];
				int ny = y - dy[dir];

				x = nx;
				y = ny;
			}
			
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
		}
	
		cout << (maxX - minX) * (maxY - minY) << "\n";
	}
	
	return 0;
}
