#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, W;
int truck[1010];
int time;

int main(void)
{
//	freopen("B13335_input.txt", "r", stdin);

	cin >> N >> L >> W;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> truck[i];
	}
	
	queue<int> q;
	int weight = 0;
	int idx = 1;
		
	while(1)
	{
		time++;
		
		if(q.size() == L)
		{
			weight -= q.front();
			q.pop();	
		}
		
		if(weight + truck[idx] <= W)
		{
			q.push(truck[idx]);
			weight += truck[idx++];
			
			if(idx == N+1)
			{
				time += L;
				break;
			}
		}
		else
		{
			q.push(0);
		}
	}
	
	cout << time;
	
	return 0;
}
