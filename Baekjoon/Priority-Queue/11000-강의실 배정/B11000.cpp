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
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	pq.push(v[0].second);
	ans = 1;
	
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i].first < pq.top())
		{
			pq.push(v[i].second);
		}
		else
		{
			pq.pop();
			pq.push(v[i].second);
		}
		
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans;
	
	return 0;
}
