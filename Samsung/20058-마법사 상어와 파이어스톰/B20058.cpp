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

int N, Q, len;
int Map[70][70];
int Max;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= len && 1 <= y && y <= len)
	{
		return 1;
	}
	
	return 0;
}

void divide_rotate(int x, int y, int size)
{
	int Temp_Map[70][70];
	int Temp_Map2[70][70];
	
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			Temp_Map[i-x+1][j-y+1] = Map[i][j];
			Temp_Map2[i-x+1][j-y+1] = Temp_Map[i-x+1][j-y+1];
		}
	}
	
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
			Temp_Map[j][size+1-i] = Temp_Map2[i][j];
		}
	}
	
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			Map[i][j] = Temp_Map[i-x+1][j-y+1];
//			cout << Map[i][j] << " ";
		}
//		cout << endl;
	}
//	cout << endl;
}

void rotate(int step)
{
	int size = pow(2, step);

	for(int i = 1; i <= len; i += size)
	{
		for(int j = 1; j <= len; j += size)
		{
			divide_rotate(i, j, size);
		}
	}
} 

int print()
{
	int sum = 0;
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			sum += Map[i][j];
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	
	return sum;
}

void melt()
{
	vector<pair<int, int>> list;
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			int cnt = 0;
			
			for(int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if(safe(nx, ny) && Map[nx][ny] >= 1)
				{
					cnt++;
				}
			}
			
			if(cnt < 3)
			{
				list.push_back({i, j});
			}
		}
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		int x = list[i].first;
		int y = list[i].second;
		
		if(Map[x][y] >= 1)
		{
			Map[x][y]--;
		}
	}
}

void find_big_ice(int x, int y, int visited[70][70])
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = 1;
	int cnt = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];			
			
			if(safe(nx, ny) == 1)
			{
				if(Map[nx][ny] >= 1 && visited[nx][ny] == 0)
				{
					q.push({nx, ny});
					visited[nx][ny] = 1;
					cnt++;
				}
			}
		}
	}
	
	Max = max(Max, cnt);
}
 
int main(void)
{
//	freopen("B20058_input.txt", "r", stdin);
	
	cin >> N >> Q;
	
	len = pow(2, N);
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			cin >> Map[i][j];		
		}
	}

	for(int i = 1; i <= Q; i++)
	{
		int step;
		cin >> step;
		
		rotate(step);
		
//		print();
//		cout << endl;
//		cout << "====melt====\n";
		
		melt();
		
//		print();
//		cout << endl;
//		cout << endl;
	}	
	
	int sum = 0;
	int visited[70][70] = {0};
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			sum += Map[i][j];
			
			if(Map[i][j] >= 1 && visited[i][j] == 0)
			{
				find_big_ice(i, j, visited);	
			}
		}
	}

	cout << sum << endl;
	cout << Max << endl;
	
	return 0;
}
