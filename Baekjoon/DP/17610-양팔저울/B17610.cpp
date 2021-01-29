#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
int choo[20];
int check[2600010][20];
int cnt;
int S;

void solve(int result, int idx)
{ 
	if(idx > N)
	{
		return;
	}
	
	if(check[result][idx] != 0)
	{
		return;
	}
	check[result][idx] = 1;
	
	solve(result + choo[idx], idx+1);
	solve(abs(result - choo[idx]), idx+1);
	solve(result, idx+1);
}

int main(void)
{
//	freopen("B17610_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> choo[i];
		
		S += choo[i];
	}
	
	solve(0, 0);
	
	for(int i = 1; i <= S; i++)
	{
		if(check[i][N] == 0)
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
