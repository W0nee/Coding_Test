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
vector<int> day[370];
int ans;

int main(void)
{
//	freopen("B20207_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int from, to;
		cin >> from >> to;
		
		for(int j = from; j <= to; j++)
		{
			day[j].push_back(1);
		}
	}
	
	int garo = 0;
	int sero = 0;
	for(int i = 1; i <= 365; i++)
	{
		if(day[i].size() == 0)
		{
			ans += garo * sero;
			
			garo = 0;
			sero = 0;
		}
		else
		{
			garo += 1;
			sero = max(sero, (int)day[i].size());
		}
	}
	
	if(garo != 0 && sero != 0)
	{
		ans += garo * sero;
	}
	
	cout << ans;
	
	return 0;
}
