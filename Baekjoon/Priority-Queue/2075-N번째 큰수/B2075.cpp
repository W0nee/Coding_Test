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

int main(void)
{
//	freopen("B2075_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int x;
			cin >> x;
			
			if(pq.size() >= N)
			{
				if(pq.top() < x)
				{
					pq.pop();
					pq.push(x);
				}
			}
			else
			{
				pq.push(x);	
			}
		}
	}
	
	cout << pq.top();
	
	return 0;
}
