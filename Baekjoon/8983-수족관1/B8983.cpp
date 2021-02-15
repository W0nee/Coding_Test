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

int N, K;
pair<int, int> depth[40010];
vector<int> hole;

int main(void)
{
//	freopen("B8983_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N;

	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	for(int i = 1; i <= N/2-1; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j = x1; j < x2; j++)
		{
			depth[j].first = y1;
		}
	}
	cin >> x1 >> y1;
	int last = x1;
	
	cin >> K;
	for(int i = 1; i <= K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		hole.push_back(x1);
	}
	
	for(int i = 0; i < hole.size(); i++)
	{
		int cur = hole[i];
		int h = depth[cur].first;
		depth[cur].second = h;
		
		for(int j = cur-1; j >= 0; j--)
		{
			h = min(h, depth[j].first);
//			depth[j].second = max(h, depth[j].second);
			depth[j].second = h;
		}
		
		h = depth[cur].first;
		for(int j = cur+1; j < last; j++)
		{
			h = min(h, depth[j].first);
//			depth[j].second = max(h, depth[j].second);
			depth[j].second = h;
		}
	}
	
	int result = 0;
	for(int i = 0; i < last; i++)
	{
		result += depth[i].first - depth[i].second;
	}
	
	cout << result;
	
	return 0;
}
