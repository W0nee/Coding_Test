#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int row, col;
int Map[5][5];
int visited[5][5];
int Max;

// 0은 가로계산, 1은 세로계산 
int cal()
{
	int val = 0;
	
	// 가로계산 
	for(int i = 1; i <= row; i++)
	{
		int num = 0;
		int cnt = 0;
		vector<int> list;
		
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				cnt++;
				list.push_back(Map[i][j]);
			}
			else
			{
				if(list.size() == 0)
				{
					continue;
				}
				else
				{
					int len = list.size();
			
					for(int k = 0; k < list.size(); k++)
					{
						num += list[k] * pow(10, len-k-1);
					}
					
					val += num;
					
					list.clear();
					num = 0;
					cnt = 0;
				}
			}
		}
		
		if(list.size() != 0)
		{
			int len = list.size();
			
			for(int k = 0; k < list.size(); k++)
			{
				num += list[k] * pow(10, len-k-1);
			}
			
			val += num;
		}
	}
	
	for(int j = 1; j <= col; j++)
	{
		int num = 0;
		int cnt = 0;
		vector<int> list;
		
		for(int i = 1; i <= row; i++)
		{
			if(visited[i][j] == 1)
			{
				cnt++;
				list.push_back(Map[i][j]);
			}
			else
			{
				if(list.size() == 0)
				{
					continue;
				}
				else
				{
					int len = list.size();
			
					for(int k = 0; k < list.size(); k++)
					{
						num += list[k] * pow(10, len-k-1);
					}
					
					val += num;
					
					list.clear();
					num = 0;
					cnt = 0;
				}
			}
		}
		
		if(list.size() != 0)
		{
			int len = list.size();
			
			for(int k = 0; k < list.size(); k++)
			{
				num += list[k] * pow(10, len-k-1);
			}
			
			val += num;
		}
	}
	
//	cout << val << endl;
	
	return val;
}

void solve(int x, int y)
{
	
	for(int i = 0; i <= 1; i++)
	{
		visited[x][y] = i;

		if(x == row && y == col)
		{
//			for(int i = 1; i <= row; i++)
//			{
//				for(int j = 1; j<= col; j++)
//				{
//					cout << visited[i][j] << " ";
//				}
//				cout << endl;
//			}
			Max = max(Max, cal());
		}
		else if(y == col)
		{
			solve(x+1, 1);
		}
		else
		{
			solve(x, y+1);
		}
	}
	
	return;
}

int main(void)
{
//	freopen("B14391_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	solve(1, 1);
	
	cout << Max;
	
	return 0;
}
