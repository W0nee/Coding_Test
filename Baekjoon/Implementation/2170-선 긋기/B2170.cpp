#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> act;
int cnt;

int main(void)
{
//	freopen("B2170_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;
	
	for(int i = 1; i <= N; i++)
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
	
	for(int i = 0; i < list.size(); i++)
	{
		cnt += list[i].second - list[i].first;
	}
	
	cout << cnt;
	
	return 0;
}
