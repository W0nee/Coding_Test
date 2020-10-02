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

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.second < b.second)
	{
		return true;
	}
	else if(a.second == b.second)
	{
		if(a.first < b.first)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

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
	
	sort(v.begin(), v.end(), cmp);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < v.size(); i++)
	{
		if(!pq.empty())
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
		}
		else
		{
			pq.push(v[i].second);
		}
		
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans;
	
	return 0;
}
