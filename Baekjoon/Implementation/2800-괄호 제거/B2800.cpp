#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int idx;

void solve(int n)
{
	if(n == 0)
	{
		if(idx+1 == N)
		{
			cout << "m";
		}
		else if(idx+2 == N || idx+3 == N)
		{
			cout << "o";
		}
		
		idx += 3;
		return;
	}
	
	solve(n-1);
	
	if(++idx == N)
	{
		cout << "m";
		return;
	}
	
	for(int i = 1; i <= n+2; i++)
	{
		if(++idx == N)
		{
			cout << "o";
			return;
		}
	}
	
	solve(n-1);
}

int main(void)
{
//	freopen("B5904_input.txt", "r", stdin);
	
	cin >> N;
	
	solve(27);
	
	return 0;
}
