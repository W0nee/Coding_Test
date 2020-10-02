#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
pair<double, double> pos[10010];
double area;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return x1*y2 + x2*y3 + x3*y1 - (x2*y1 + x3*y2 + x1*y3);
}

int main(void)
{
//	freopen("B2166_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	
	double stdX = pos[1].first;
	double stdY = pos[1].second;
	
	for(int i = 2; i <= N-1; i++)
	{
		area += ccw(stdX, stdY, pos[i].first, pos[i].second, pos[i+1].first, pos[i+1].second) / 2.0;
	}
	
	printf("%0.1lf", abs(area));
	
	return 0;
}
