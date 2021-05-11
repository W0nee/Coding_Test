#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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
	
	for(int i = 2; i <= W-1; i++)
	{
		int leftMax = height[i];
		int rightMax = height[i];
		
		// left
		for(int j = 1; j <= i-1; j++)
		{
			leftMax = max(leftMax, height[j]);
		}
		
		// right
		for(int j = i+1; j <= W; j++)
		{
			rightMax = max(rightMax, height[j]);
		}
		
		result[i] = min(leftMax, rightMax);
	}
	
	for(int i = 2; i <= W-1; i++)
	{
		ans += result[i] - height[i];
	}
	
	cout << ans;
 	
	return 0;
}
