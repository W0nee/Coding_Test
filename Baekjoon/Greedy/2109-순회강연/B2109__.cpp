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
int money;

int main(void)
{
//	freopen("B2109_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int pay, day;
		cin >> pay >> day;
		v.push_back({day, pay});
	}
	
	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < v.size(); i++)
	{
		pq.push(v[i].second);
		money += v[i].second;
		
		if(pq.size() > v[i].first)
		{
			money -= pq.top();
			pq.pop();
		}
	}
	
	cout << money;
	
	return 0;
}
