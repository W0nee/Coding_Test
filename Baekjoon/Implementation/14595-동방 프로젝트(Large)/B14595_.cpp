#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> act;
int visited[1000010];
int cnt;

int main(void)
{
//	freopen("B14595_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	if(M == 0)
	{
		cout << N;
		return 0;
	}
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		act.push_back({from, to});
	}
	
	sort(act.begin(), act.end());
	
	vector<pair<int, int>> list;
	int start = act[0].first;
	int arrive = act[0].second;
	
	for(int i = 1; i < act.size(); i++)
	{
		if(arrive < act[i].first)
		{
			list.push_back({start, arrive});
			
			start = act[i].first;
			arrive = act[i].second;
		}
		else
		{
			arrive = max(arrive, act[i].second);
		}
	}
	list.push_back({start, arrive});
	
//	for(int i = 0; i < list.size(); i++)
//	{
//		cnt += list[i].second - list[i].first;
//	}
//	
//	cout << N - cnt;

	for(int i = 0; i < list.size(); i++)
	{
		int left = list[i].first;
		int right = list[i].second;
		
		for(int j = left; j <= right; j++)
		{
			visited[j] = 1;
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
		{
			cnt++;
		}
	}
	
	cout << cnt + list.size();
	
	return 0;
}
