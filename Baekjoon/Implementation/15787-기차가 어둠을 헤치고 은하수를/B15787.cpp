#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
deque<int> result[100010];

int main(void)
{
//	freopen("B15787_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= 20; j++)
		{
			result[i].push_back(0);
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		int command, train, seat;
		cin >> command;
		
		if(command == 1 || command == 2)
		{
			cin >> train >> seat;
			
			if(command == 1)
			{
				result[train][seat-1] = 1;
			}
			else
			{
				result[train][seat-1] = 0;	
			}
		}
		else
		{
			cin >> train;
			
			if(command == 3)
			{
				result[train].pop_back();
				result[train].push_front(0);
			}
			else
			{
				result[train].pop_front();
				result[train].push_back(0);
			}
		}
	}
	
	map<string, int> check;
	int cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		string temp = "";
		
		for(int j = 0; j < result[i].size(); j++)
		{
			temp += result[i][j];
		}
		
		if(check[temp] == 0)
		{
			check[temp] = 1;
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
