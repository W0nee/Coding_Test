#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int ans;

int main(void)
{
//	freopen("B11000_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<int> pq;
	
	for(int i = v.size()-1; i >= 0; i--)
	{
		if(!pq.empty())
		{
			if(v[i].second > pq.top())
			{
				pq.push(v[i].first);
				cout << "only push : " << v[i].first << endl;
			}
			else
			{
				cout << "pq.top : " << pq.top() << endl;
 				pq.pop();
				pq.push(v[i].first);
				cout << "pop push : " << v[i].first << endl;
			}	
		}
		else
		{
			pq.push(v[i].first);
		}
		
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans;
	
	return 0;
}

/*
7
1 7
3 10
4 6
9 17
9 20
11 12
12 14
*/
