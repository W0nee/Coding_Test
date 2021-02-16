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

typedef struct node
{
	int x1;
	int y1;
	int x2;	
	int y2;
}node;

int N, K;
pair<int, int> pos[5010];
pair<int, int> value[40010];
node hole[2510];
int ans;

bool cmp(node a, node b)
{
	if(a.x1 < b.x1)
	{
		return true;
	}
	
	return false;
}

int main(void)
{
//	freopen("B8982_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	
	for(int i = 2; i <= N-1; i += 2)
	{
		int x1 = pos[i].first;
		int y1 = pos[i].second;
		int x2 = pos[i+1].first;
		int y2 = pos[i+1].second;
		
		for(int j = x1; j < x2; j++)
		{
			value[j].first = y1;
		}
	}
	
	cin >> K;
	
	for(int i = 1; i <= K; i++)
	{
		cin >> hole[i].x1 >> hole[i].y1 >> hole[i].x2 >> hole[i].y2;
	}
	
	sort(hole+1, hole+K+1, cmp);
	
	for(int i = 1; i <= K; i++)
	{
		int x = hole[i].x1;
		int y = hole[i].y1;
		int h = y;
		
		for(int j = x; j >= 0; j--)
		{
			h = min(h, value[j].first);
			value[j].second = max(h, value[j].second);
		}
		
		h = y;
		
		for(int j = x+1; j < pos[N].first; j++)
		{
			h = min(h, value[j].first);
			value[j].second = max(h, value[j].second);
		}
	}
	
	for(int i = 0; i < pos[N].first; i++)
	{
		ans += value[i].first - value[i].second;
	}
	
	cout << ans;

	return 0;
}
