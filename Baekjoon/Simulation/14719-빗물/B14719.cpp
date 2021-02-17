#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
int block[510];
pair<int, int> value[510];
int ans;

int main(void)
{
//	freopen("B1062_input.txt", "r", stdin);
	
	cin >> H >> W;
	
	for(int i = 1; i <= W; i++)
	{
		cin >> block[i];
		
		value[i].first = block[i];
	}
	
	for(int i = 2; i <= W-1; i++)
	{
		int leftMax = block[i];
		int rightMax = block[i];
		
		for(int j = i-1; j >= 1; j--)
		{
			leftMax = max(leftMax, block[j]);
		}
		
		for(int j = i+1; j <= W; j++)
		{
			rightMax = max(rightMax, block[j]);
		}
		
		value[i].second = min(leftMax, rightMax);
	}
	
	for(int i = 2; i <= W-1; i++)
	{
		ans += (value[i].second - value[i].first);
	}
	
	cout << ans;
	
	return 0;
}
