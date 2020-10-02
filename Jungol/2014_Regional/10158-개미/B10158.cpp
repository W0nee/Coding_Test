#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int garo, sero;
int x, y;
int time;

int main(void)
{
//	freopen("B10158_input.txt", "r", stdin);

	cin >> garo >> sero >> x >> y >> time;
	
	int garoCnt = time % (2 * garo);
	int seroCnt = time % (2 * sero);
	int dx = 1;
	int dy = 1;
	
	for(int i = 1; i <= garoCnt; i++)
	{
		if(x == garo)
		{
			dx = -1;
		}
		else if(x == 0)
		{
			dx = 1;
		}
		
		x += dx;
	}
	
	for(int i = 1; i <= seroCnt; i++)
	{
		if(y == sero)
		{
			dy = -1;
		}
		else if(y == 0)
		{
			dy = 1;
		}
		
		y += dy;
	}
	
	cout << x << " " << y << endl;
	
	return 0;
}
