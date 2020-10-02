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
int Max;

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
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < N; i++)
	{
		while(!pq.empty() && pq.top() <= v[i].first)
		{
			pq.pop();
		}
		
		pq.push(v[i].second);
		
		Max = max(Max, (int)pq.size());
	}
	
	cout << Max;
	
	return 0;
}
