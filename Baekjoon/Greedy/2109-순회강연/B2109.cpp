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
int check[10010];
vector<pair<int, int>> list;
int ans;

int main(void)
{
//	freopen("B2109_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int p, d;
		cin >> p >> d;
		
		list.push_back({p, d});
	}
	
	sort(list.begin(), list.end(), greater<pair<int, int>>());
	
	for(int i = 0; i < list.size(); i++)
	{
		int price = list[i].first;
		int day = list[i].second;
		
		for(int j = day; j >= 1; j--)
		{
			if(check[j] == 0)
			{
				check[j] = 1;
				ans += price;
				break;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
