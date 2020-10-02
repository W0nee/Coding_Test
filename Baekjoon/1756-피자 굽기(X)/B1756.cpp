#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int D;
int N;
int Min[300010];

int main(void)
{
//	freopen("B1756_input.txt", "r", stdin);
	
	cin >> D >> N;
	
	for(int i = 1; i <= D; i++)
	{
		int d;
		cin >> d;
		
		if(i == 1)
		{
			Min[i] = d;
		}
		else
		{
			Min[i] = min(Min[i-1], d);	
		}
	}
	
	int minIdx = D;
	for(int i = 1; i <= N; i++)
	{
		int d;
		cin >> d;
		
		while(minIdx >= 1 && Min[minIdx] < d)
		{
			minIdx--;
		}
		minIdx--;
	}
	
	if(minIdx <= -1)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << minIdx+1 << endl;
	}
	
	return 0;
}
