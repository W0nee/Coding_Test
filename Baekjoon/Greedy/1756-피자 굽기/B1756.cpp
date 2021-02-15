#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int D;
int N;
int oven[300010];
int Min = 987654321;
int ans;

int main(void)
{
//	freopen("B1756_input.txt", "r", stdin);
	
	cin >> D >> N;
	
	for(int i = 1; i <= D; i++)
	{	
		int d;
		cin >> d;
		
		Min = min(Min, d);
		
		oven[i] = Min;
	}
	
	int idx = D;
	for(int i = 1; i <= N; i++)
	{
		int pizza;
		cin >> pizza;
		
		while(idx >= 1 && oven[idx] < pizza)
		{
			idx--;
		}
		
		if(idx <= 0)
		{
			cout << "0";
			return 0;
		}
		
		if(oven[idx] >= pizza)
		{
			ans = idx;
			idx--;
		}
	}
	
	cout << ans;
	
	return 0;
}
