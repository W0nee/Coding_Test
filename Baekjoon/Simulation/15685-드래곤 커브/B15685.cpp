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

int N;
int Map[110][110];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void move(int x, int y, vector<int> result)
{
	for(int i = 0; i < result.size(); i++)
	{
		int nx = x+dx[result[i]];
		int ny = y+dy[result[i]];
		
		Map[ny][nx] = 1;
		
		x = nx;
		y = ny;
	}
}

int cal()
{
	int nemo = 0;
	
	for(int i = 0; i <= 99; i++)
	{
		for(int j = 0; j <= 99; j++)
		{
			int cnt = 0;
			
			for(int m = i; m <= i+1; m++)
			{
				for(int n = j; n <= j+1; n++)
				{
					if(Map[m][n] == 1)
					{
						cnt++;
					}
				}
			}
			
			if(cnt == 4)
			{
				nemo++;
			}
		}
	}
	
	return nemo;
}

int main(void)
{
//	freopen("B15685_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int x, y, dir, cnt;
		cin >> x >> y >> dir >> cnt;
		
		vector<int> result;
		result.push_back(dir);
			
		for(int k = 1; k <= cnt; k++)
		{
			vector<int> temp = result;
			reverse(temp.begin(), temp.end());
			
			for(int i = 0; i < temp.size(); i++)
			{
				temp[i] = (temp[i] + 1) % 4;
				result.push_back(temp[i]);
			}
		}
		
		Map[y][x] = 1;
		move(x, y, result);
	}
	
	cout << cal();
	
	return 0;
}
