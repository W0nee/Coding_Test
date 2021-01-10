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

int row, col;
int Map[5][5];
int visited[5][5];
int Max;

int convert(vector<int> num)
{
	int val = 0;
	int n = (int)num.size();
	
	for(int i = 0; i < n; i++)
	{
		val += num[i] * pow(10, n-i-1);
	}
	
	return val;
}

int cal()
{
	int sum = 0;
	int check[5][5] = {0};
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(check[i][j] == 0)
			{
				if(visited[i][j] == 1)
				{
					vector<int> garo;
					
					for(int k = j; k <= col; k++)
					{
						if(visited[i][k] == 1)
						{
							check[i][k] = 1;
							garo.push_back(Map[i][k]);	
						}
						else
						{
							break;
						}
					}
					
					sum += convert(garo);
				}
				else
				{
					vector<int> sero;
					
					for(int k = i; k <= row; k++)
					{
						if(visited[k][j] == 2)
						{
							check[k][j] = 1;
							sero.push_back(Map[k][j]);	
						}
						else
						{
							break;
						}
					}
					
					sum += convert(sero);
				}
			}
		}
	}
	
	return sum;
}

void DFS(int x, int y)
{
	if(x == row && y == col)
	{
		Max = max(Max, cal());
		return;
	}
		
	for(int i = 1; i <= 2; i++)
	{
		if(y == col)
		{
			visited[x+1][1] = i;
			DFS(x+1, 1);
			visited[x+1][1] = 0;
		}	
		else
		{
			visited[x][y+1] = i;
			DFS(x, y+1);
			visited[x][y+1] = 0;
		}		
	}
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
	
	for(int i = 1; i <= 2; i++)
	{
		visited[1][1] = i;
		DFS(1, 1);
		visited[1][1] = 0;
	}
	
	cout << Max;
	
	return 0;
}
