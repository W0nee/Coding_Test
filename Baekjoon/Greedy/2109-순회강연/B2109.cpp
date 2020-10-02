#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int visited[10010];
int Max;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first > b.first)
	{
		return true;
	}
	else if(a.first == b.first)
	{
		if(a.second > b.second)
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
	
	int date_max = 0;
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		v.push_back({a, b});
		
		if(date_max < b)
		{
			date_max = b;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
//	for(int i = 0; i < N; i++)
//	{
//		cout << v[i].first << " " << v[i].second << endl;
//	}
	
	int date = 1;
	int idx = 0;
	while(date <= date_max)
	{
		for(int i = idx; i < N; i++)
		{
			bool flag = false;
			
			for(int j = v[i].second; j >= 1; j--)
			{
				if(visited[j] == 0)
				{
					flag = true;
					
					visited[j] = 1;
					idx = i+1;
					Max += v[i].first;
					break;
				}
			}
			
			if(flag)
			{
				break;
			}
			
		}

		date++;
	}
	
	cout << Max;
	
	return 0;
}
