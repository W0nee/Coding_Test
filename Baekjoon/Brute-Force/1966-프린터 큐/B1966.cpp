#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int T;
int N, M;

int Find(deque<pair<int, int>> q)
{
	int Max = -1;
	
	for(int i = 0; i < q.size(); i++)
	{
		if(Max < q[i].first)
		{
			Max = q[i].first;
		}
	}
	
	return Max;
}

int main(void)
{
//	freopen("B1966_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		deque<pair<int, int>> q;
		
		cin >> N >> M;
		
		for(int i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			
			q.push_back({input, i});
		}
		
		int order = 0;
		while(1)
		{
			int Max = Find(q);
			int tempVal = q.front().first;
			int tempNum = q.front().second;
			q.pop_front();
			
			if(Max == tempVal)
			{
				order++;
				
				if(tempNum == M)
				{
					cout << order << endl;
					break;	
				}
			}
			else
			{
				q.push_back({tempVal, tempNum});
			}
		}	
	}
	
	return 0;
}
