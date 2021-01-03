#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int date;
int ans;

int main(void)
{
//	freopen("B2109_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int pay, day;
		cin >> pay >> day;
		
		v.push_back({day, pay});
		
		if(date < day)
		{
			date = day;
		}
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, less<int>> pq;
	
	int idx = v.size()-1;
	for(int i = date; i >= 1; i--)
	{
		while(idx >= 0 && i <= v[idx].first)
		{
			pq.push(v[idx--].second);
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
