#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Num[25][25];
int Map[25][25];
int Min = 99999999;

void Paint()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Map[i][j] == 5)
			{
				int start = j;
				int arrive = 0;
				
				for(int k = j+1; k <= N; k++)
				{
					if(Map[i][k] == 5)
					{
						arrive = k;
						break;
					}
				}
				
				for(int k = start; k <= arrive; k++)
				{
					Map[i][k] = 5;
				}
				
				break;
			}
		}
	}
}

void Limit(int x, int y, int d1, int d2)
{
	// 1번 경계선
	for(int i = 0; i <= d1; i++)
	{
		int nx = x+i;
		int ny = y-i;
		
		Map[nx][ny] = 5;
	}
	
	// 2번 경계선 
	for(int i = 0; i <= d2; i++)
	{
		int nx = x+i;
		int ny = y+i;
		
		Map[nx][ny] = 5;
	}
	
	// 3번 경계선
	for(int i = 0; i <= d2; i++)
	{
		int nx = x+d1+i;
		int ny = y-d1+i;
		
		Map[nx][ny] = 5;
	}
	
	// 4번 경계선
	for(int i = 0; i <= d1; i++)
	{
		int nx = x+d2+i;
		int ny = y+d2-i;
		
		Map[nx][ny] = 5;
	}
}

int Divide(int x, int y, int d1, int d2)
{
	// 1번 선거구
	for(int i = 1; i < x+d1; i++) 
	{
		for(int j = 1; j <= y; j++)
		{
			if(Map[i][j] != 5)
			{
				Map[i][j] = 1;
			}
		}
	}
	
	// 2번 선거구
	for(int i = 1; i <= x+d2; i++) 
	{
		for(int j = y+1; j <= N; j++)
		{
			if(Map[i][j] != 5)
			{
				Map[i][j] = 2;
			}
		}
	}
	
	// 3번 선거구
	for(int i = x+d1; i <= N; i++) 
	{
		for(int j = 1; j < y-d1+d2; j++)
		{
			if(Map[i][j] != 5)
			{
				Map[i][j] = 3;
			}	
		}
	}
	
	// 4번 선거구
	for(int i = x+d2+1; i <= N; i++) 
	{
		for(int j = y-d1+d2; j <= N; j++)
		{
			if(Map[i][j] != 5)
			{
				Map[i][j] = 4;
			}	
		}
	}
	
	int Max = -99999999;
	int Min = 99999999;
	int people[10] = {0};
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Map[i][j] == 0)
			{
				people[5] += Num[i][j];
			}
			else
			{
				people[Map[i][j]] += Num[i][j];	
			}
		}
	}
	
	for(int i = 1; i <= 5; i++)
	{
		Max = max(Max, people[i]);
		Min = min(Min, people[i]);
	}
	
	return Max-Min;
}

int main(void)
{
//	freopen("B17779_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Num[i][j];
		}
	}
	
	for(int x = 1; x <= N; x++)
	{
		for(int y = 1; y <= N; y++)
		{
			for(int d1 = 1; d1 <= N; d1++)
			{
				for(int d2 = 1; d2 <= N; d2++)
				{
					if(x+d1+d2 <= N && 1 <= y-d1 && y+d2 <= N)
					{
						memset(Map, 0, sizeof(Map));
						Limit(x, y, d1, d2);
						Paint();
						Min = min(Min, Divide(x, y, d1, d2)); 
					}
				}
			}
		}
	}
	
	cout << Min;
	
	return 0;
}
