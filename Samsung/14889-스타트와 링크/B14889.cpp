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

int N;
int Map[25][25];
vector<int> start;
int visited[25];
int Min = 99999999;

void combination(int idx, int cnt)
{
	if(cnt == N/2)
	{
		vector<int> link;
		
		for(int i = 0; i < N; i++)
		{
			if(visited[i] == 0)
			{
				link.push_back(i);	
			}
		}
		
		int sum1 = 0;
		for(int i = 0; i < start.size(); i++)
		{
			for(int j = 0; j < start.size(); j++)
			{
				if(i == j)
				{
					continue;
				}
				
				sum1 += Map[start[i]][start[j]];
			}
		}
		
		int sum2 = 0;
		for(int i = 0; i < link.size(); i++)
		{
			for(int j = 0; j < link.size(); j++)
			{
				if(i == j)
				{
					continue;
				}
				
				sum2 += Map[link[i]][link[j]];
			}
		}
		
		Min = min(Min, abs(sum1-sum2));
		
		return;
	}
	
	for(int i = idx; i < N; i++)
	{
		visited[i] = 1;
		start.push_back(i);
		combination(i+1, cnt+1);
		start.pop_back();
		visited[i] = 0;
	}
}

int main(void)
{
//	freopen("B14889_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	combination(0, 0);
	
	cout << Min;
	
	return 0;
}
