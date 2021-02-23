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

typedef struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if(a.first > b.first)
		{
			return true;
		}
		else if(a.first == b.first)
		{
			if(a.second > b.second)
			{
				return true;
			}
			
			return false;
		}
		
		return false;
	}
}cmp;

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main(void)
{
//	freopen("B11286_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int val;
		cin >> val;
		
		if(pq.empty() && val == 0)
		{
			cout << "0\n";
		}
		else if(val == 0)
		{
			cout << pq.top().second << "\n";
			pq.pop();
		}
		else
		{
			pq.push({abs(val), val});
		}		
	}
	
	return 0;
}
