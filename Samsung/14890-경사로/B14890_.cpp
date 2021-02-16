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

int N, L;
int Map1[110][110];
int Map2[110][110];
int ans;

int make_road(int Map[110][110], int x, int y)
{
	for(int j = y; j <= y+L-1; j++)
	{
		if(Map[x][y] != Map[x][j])
		{
			return 0;
		}
	}
	
	return 1;
}

void solve(int Map[110][110])
{
	for(int i = 1; i <= N; i++)
	{
		bool can_road = true;
		int val = Map[i][1];
		int cnt = 1;
		
		for(int j = 2; j <= N; j++)
		{
			// flat
			if(val == Map[i][j])
			{
				cnt++;
			}
			// up
			else if(val + 1 == Map[i][j])
			{
				if(cnt >= L)
				{
					cnt = 1;
					val = Map[i][j];
				}
				else
				{
					can_road = false;
					break;
				}
			}
			// down
			else if(val == Map[i][j] + 1)
			{
				if(make_road(Map, i, j) == 1)
				{
					j = j + L - 1;
					cnt = 0;
					val = Map[i][j];
				}
				else
				{
					can_road = false;
					break;
				}
			}
			else if(abs(val - Map[i][j]) >= 2)
			{
				can_road = false;
				break;
			}
		}
		
		if(can_road)
		{
			ans++;
		}
	}
}

int main(void)
{
//	freopen("B1062_input.txt", "r", stdin);
	
	cin >> N >> L;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map1[i][j];
			
			Map2[j][i] = Map1[i][j];
		}
	}

	solve(Map1);
	solve(Map2);
	
	cout << ans;
	
	return 0;
}
