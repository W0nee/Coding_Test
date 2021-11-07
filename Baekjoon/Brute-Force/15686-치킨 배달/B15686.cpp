#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ladder[40][20];
int N, M, H;
bool Flag = false;

int check()
{
	for(int i = 1; i <= N; i++) 
	{
		int nowX = 1;
		int nowY = i;
		
		while(1)
		{
			if(ladder[nowX][nowY] == 1) 
			{
				nowX++;
				nowY++;
			}
			else if(ladder[nowX][nowY-1] == 1)
			{
				nowX++;
				nowY--;
			}
			else
			{
				nowX++;
			}
			
			if(nowX == H+1)
			{
				if(nowY == i)
				{
					break;
				}
				else
				{
					return 0;
				}
			}
		}
	}	
	
	return 1;
}

void DFS(int idx, int cnt, int k) 
{	
	if(cnt == k)
	{
		if(check() == 1)
		{
			Flag = true;
		}
		
		return;
	}
	
	for(int i = idx; i <= H; i++)
	{
		for(int j = 1; j <= N-1; j++)
		{
			if(ladder[i][j-1] == 1 || ladder[i][j] == 1) 
			{
				continue;
			}	
			
			if(j == N-1)
			{
				ladder[i][j] = 1;
				DFS(i+1, cnt+1, k);
				ladder[i][j] = 0;
			}
			else
			{
				ladder[i][j] = 1;
				DFS(i, cnt+1, k);
				ladder[i][j] = 0;
			}
			
			if(Flag)
			{
				return;
			}
		}
		
		if(Flag)
		{
			return;
		}
	}
}

int main(void)
{
//	freopen("B15686_input.txt", "r", stdin);

	cin >> N >> M >> H;
	
	for(int i = 1; i <= M; i++) 
	{
		
		int a, b;
		cin >> a >> b;
		
		ladder[a][b] = 1;
	}
	
	for(int i = 0; i <= 3; i++) 
	{
		DFS(1, 0, i);
		if(Flag)
		{
			cout << i;
			return 0;
		}
	}
	
	if(Flag == false)
	{
		cout << "-1";
	}
	
	return 0;
}
