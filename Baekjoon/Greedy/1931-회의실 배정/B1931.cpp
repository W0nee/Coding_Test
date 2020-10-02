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
int cnt = 1;

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
//	freopen("B1931_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), cmp);

	int std = v[0].second;
	for(int i = 1; i < v.size(); i++)
	{
		if(std <= v[i].first)
		{
			cnt++;
			std = v[i].second;
		}
	}
	
	cout << cnt;
	
	return 0;
}
