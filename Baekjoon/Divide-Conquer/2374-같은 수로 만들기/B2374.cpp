#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[1010];
long long cnt;

int dx[2] = {-1, 1};

void BFS(int x)
{
	queue<int> q;
	int visited[1010] = {0};
	vector<int> list;
	
	q.push(x);
	visited[x] = 1;
	
	int Min = 1000000010;
	int value = A[x];
	list.push_back(x);
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		
		for(int i = 0; i < 2; i++)
		{
			int nx = x+dx[i];
			
			if(1 <= nx && nx <= N)
			{
				if(A[nx] == value && visited[nx] == 0)
				{
					q.push(nx);
					visited[nx] = 1;
					
					list.push_back(nx);
				}
				else if(A[nx] != value)
				{
					Min = min(Min, A[nx]);
				}
			}	
		}
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		A[list[i]] = Min;
	}
	
	cnt += Min - value;
}

void print()
{
	for(int i = 1; i <= N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << cnt << endl;
}

int check()
{
	int std = A[1];
	
	for(int i = 2; i <= N; i++)
	{
		if(A[i] != std)
		{
			return 0;
		}
	}
	
	return 1;
}

int main(void)
{
//	freopen("B2374_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	
	while(!check())
	{
		int Min = 1000000010;
		int minIdx;
		
		for(int i = 1; i <= N; i++)
		{
			if(A[i] < Min)
			{
				Min = A[i];
				minIdx = i;
			}
		}
		
		BFS(minIdx);
	}
	
	cout << cnt;
	
	return 0;
}
