#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int d[110][110];

void floyd()
{
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B11404_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			d[i][j] = 999999999;
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		if(d[from][to] != 0)
		{
			d[from][to] = min(d[from][to], cost);
		}
		else
		{
			d[from][to] = cost;	
		}
	}
	
	floyd();
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(i == j || d[i][j] == 999999999)
			{
				cout << "0 ";
			}
			else
			{
				cout << d[i][j] << " ";	
			}
		}
		cout << endl;
	}
		
	return 0;
}
