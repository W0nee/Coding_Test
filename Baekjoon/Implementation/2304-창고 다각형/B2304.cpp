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
int pos[1010];
int startX, arriveX;
int result;

int main(void)
{
//	freopen("B2304_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		
		pos[x] = y;
		
		startX = min(startX, x);
		arriveX = max(arriveX, x);
	}
	
	for(int i = 1; i <= 1000; i++)
	{
		int leftMax = pos[i];
		int rightMax = pos[i];
		
		for(int j = 1; j < i; j++)
		{
			leftMax = max(leftMax, pos[j]);
		}
		
		for(int j = i+1; j <= 1000; j++)
		{
			rightMax = max(rightMax, pos[j]);
		}
		
		pos[i] = min(leftMax, rightMax);
	}
	
	for(int i = startX; i <= arriveX; i++)
	{
		result += pos[i];
	}
	
	cout << result;
	
	return 0;
}
