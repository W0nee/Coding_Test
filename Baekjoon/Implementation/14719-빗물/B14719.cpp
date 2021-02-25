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

int H, W;
int height[510];
int result[510];
int ans;

int main(void)
{
//	freopen("B14719_input.txt", "r", stdin);
	
	cin >> H >> W;
	
	for(int i = 1; i <= W; i++)
	{
		cin >> height[i];
	}
	
	for(int i = 1; i <= W; i++)
	{
		int leftMax = height[i];
		int rightMax = height[i];
		
		for(int j = 1; j < i; j++)
		{
			leftMax = max(leftMax, height[j]);
		}
		
		for(int j = i+1; j <= W; j++)
		{
			rightMax = max(rightMax, height[j]);
		}
		
		result[i] = min(leftMax, rightMax);
	}
	
	for(int i = 1; i <= W; i++)
	{
		ans += abs(result[i] - height[i]);
	}
	
	cout << ans;
	
	return 0;
}
