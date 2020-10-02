#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
double num[100010];
double Max = -999999999;

int main(void)
{
//	freopen("B1912_input.txt", "r", stdin);
	
	cin >> N;
	
	double val = 1;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		val = max(val * num[i], num[i]);
		Max = max(Max, val);
	}
	
	printf("%.3lf", Max);
	
	return 0;
}
