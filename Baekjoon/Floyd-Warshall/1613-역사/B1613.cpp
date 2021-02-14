#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, K, S;
vector<int> graph[410];
int d[410][410];

void floyd()
{
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(d[i][k] == 1 && d[k][j] == 1)
				{
					d[i][j] = 1;
				}		
			}
		}	
	}
}

int main(void)
{
//	freopen("B1613_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			d[i][j] = INF;
		}
	}
	
	for(int i = 1; i <= K; i++)
	{
		int from, to;
		cin >> from >> to;
		
		d[from][to] = 1;
	}
	
	floyd();
	
	cin >> S;
	
	for(int i = 1; i <= S; i++)
	{
		int from, to;
		cin >> from >> to;
		
		if(d[from][to] == 1)
		{
			cout << "-1\n";
		}
		else if(d[to][from] == 1)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	
	return 0;
}
