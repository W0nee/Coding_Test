#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int Map[710][710];
int eat[1500];

int main(void)
{
//	freopen("B10836_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			Map[i][j] = 1;
		}
	}
	
	while(M--)
	{
		int zero, one, two;
		cin >> zero >> one >> two;
	
		int idx = 1;
		for(int i = 1; i <= zero; i++)
		{
			eat[idx++] += 0;
		}
		for(int i = 1; i <= one; i++)
		{
			eat[idx++] += 1;
		}
		for(int i = 1; i <= two; i++)
		{
			eat[idx++] += 2;
		}
	}
	
	int x = N;
	int y = 1;
	for(int i = 1; i <= 2*N-1; i++)
	{
		if(x == 1)
		{
			Map[x][y] += eat[i];
			y++;
		}
		else if(x >= 2)
		{
			Map[x][y] += eat[i];
			x--;	
		}
	}
	
	for(int i = 2; i <= N; i++)
	{
		for(int j = 2; j <= N; j++)
		{
			int maxEat = 0;
			maxEat = max({Map[i][j-1], Map[i-1][j-1], Map[i-1][j]}) - 1;
			
			Map[i][j] += maxEat;
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
