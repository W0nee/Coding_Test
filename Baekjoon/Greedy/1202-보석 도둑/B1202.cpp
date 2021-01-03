#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> jewel[300010];
int bag[300010];
long long ans;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first < b.first)
	{
		return true;
	}
	
	return false;
}

int main(void)
{
//	freopen("B1202_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++)
	{
		cin >> jewel[i].first >> jewel[i].second;
	}
	
	for(int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}
	
	sort(jewel, jewel+N, cmp);
	sort(bag, bag+K);
	
	priority_queue<int, vector<int>, less<int>> pq;
	
	int idx = 0;
	for(int i = 0; i < K; i++)
	{
		while(idx < N && jewel[idx].first <= bag[i])
		{
			pq.push(jewel[idx++].second);
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
