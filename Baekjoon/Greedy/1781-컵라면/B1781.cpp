#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int ans;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first == b.first)
	{
		if(a.second < b.second)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

int main(void)
{
//	freopen("B1781_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), cmp);

	priority_queue<int> pq;
	int idx = v.size()-1;
	
	for(int i = N; i >= 1; i--)
	{
		while(v[idx].first == i)
		{
			pq.push(v[idx].second);
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
