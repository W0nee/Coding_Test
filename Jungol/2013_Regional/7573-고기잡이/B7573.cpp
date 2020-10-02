#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
int len, fishCnt;
vector<pair<int, int>> fish;
int Max = 1;

int cal(pair<int, int> fish1, pair<int, int> fish2, int addx, int addy)
{
	int sx = min(fish1.first, fish2.first);
	int sy = min(fish1.second, fish2.second);
	
	int cnt = 0;
	
	for(int i = 0; i < fish.size(); i++)
	{
		if(sx <= fish[i].first && fish[i].first <= sx+addx && sy <= fish[i].second && fish[i].second <= sy+addy)
		{
			cnt++;
		}
	}
	
	return cnt;
}

int main(void)
{
//	freopen("B7573_input.txt", "r", stdin);

	cin >> N >> len >> fishCnt;
	
	for(int i = 1; i <= fishCnt; i++)
	{
		int x, y;
		cin >> x >> y;
		
		fish.push_back({x, y});
	}
	
	for(int i = 0; i < fish.size()-1; i++)
	{
		for(int j = i+1; j < fish.size(); j++)
		{
			for(int k = 1; k < len/2; k++)
			{
				Max = max(Max, cal(fish[i], fish[j], k, len/2-k));	
			}
		}
	}
	
	cout << Max;
	
	return 0;
}
