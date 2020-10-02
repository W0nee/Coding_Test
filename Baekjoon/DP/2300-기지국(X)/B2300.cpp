#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> list;

int solve()
{
	int val = 0;
	int len = 2;
	int stdX = list[0].first;
	int stdY = list[0].second;
	
	for(int i = 1; i < list.size(); i++)
	{
		if(list[i].first - stdX <= val && list[i].second - stdY <= val)
		{
			
		}
	}
	
		
	
	return val;
}

int main(void)
{
//	freopen("B2300_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		
		list.push_back({x, y});
	}
	
	sort(list.begin(), list.end());
	
	return 0;
}
