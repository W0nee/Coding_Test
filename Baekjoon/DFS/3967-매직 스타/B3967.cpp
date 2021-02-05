#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char Map[10][10];
vector<pair<int, int>> list;
int visited[13];
bool Flag = false;

void print()
{
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			cout << Map[i][j];
		}
		cout << "\n";
	}
}

int check_cal()
{
	for(int i = 1; i <= 5; i++)
	{
		int sum = 0;
		
		if(i == 1)
		{
			sum = (Map[1][5] - 'A') + (Map[2][4] - 'A') + (Map[3][3] - 'A') + (Map[4][2] - 'A') + 4;
			
			if(sum != 26)
			{
				return 0;
			}
			
			sum = 0;
			sum = (Map[1][5] - 'A') + (Map[2][6] - 'A') + (Map[3][7] - 'A') + (Map[4][8] - 'A') + 4;
			
			if(sum != 26)
			{
				return 0;
			}
		}
		else if(i == 2 || i == 4)
		{
			for(int j = 2; j <= 9; j += 2)
			{
				if('A' <= Map[i][j] && Map[i][j] <= 'L')
				{
					sum += (Map[i][j] - 'A') + 1;	
				}
			}
			
			if(sum != 26)
			{
				return 0;
			}
		}
		else if(i == 5)
		{
			sum = (Map[5][5] - 'A') + (Map[4][4] - 'A') + (Map[3][3] - 'A') + (Map[2][2] - 'A') + 4;
			
			if(sum != 26)
			{
				return 0;
			}
			
			sum = 0;
			sum = (Map[5][5] - 'A') + (Map[4][6] - 'A') + (Map[3][7] - 'A') + (Map[2][8] - 'A') + 4;
			
			if(sum != 26)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void permutation(int cnt)
{
//	cout << cnt << "\n";
	
	if(cnt == list.size())
	{
		if(check_cal() == 1)
		{
			Flag = true;
			print();
		}
		
		return;
	}
	
	int x = list[cnt].first;
	int y = list[cnt].second;
	
	for(int i = 0; i < 12; i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			Map[x][y] = 'A' + i;
			permutation(cnt+1);
			if(Flag)
			{
				return;
			}
			Map[x][y] = 'x';
			visited[i] = 0;
		}	
	}
}

int main(void)
{
//	freopen("B3967_input.txt", "r", stdin);
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'x')
			{
				list.push_back({i, j});
			}
			else if('A' <= Map[i][j] && Map[i][j] <= 'L')
			{
				visited[Map[i][j]-'A'] = 1;
			}
		}
	}
	
	permutation(0);
	
	return 0;
}
