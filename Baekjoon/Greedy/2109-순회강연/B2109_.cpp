#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int date;
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
//	freopen("B2109_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		v.push_back({a, b});
		
		if(date < b)
		{
			date = b;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	priority_queue<int> pq;
	int idx = v.size()-1;
	
	for(int i = date; i >= 1; i--)
	{
		while(v[idx].second == i)
		{
			pq.push(v[idx].first);
			idx--;
		}
		
		if(!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans;
	
	return 0;
}
