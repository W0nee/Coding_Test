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
int choo[40];
int check[15010][40];
int goal;

void solve(int result, int idx)
{ 
	if(idx > N+1)
	{
		return;
	}
	else if(check[result][idx] == 1)
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
//	freopen("B2629_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> choo[i];
	}
	
	solve(0, 1);
	
	cin >> T;
	
	while(T--)
	{
		cin >> goal;
		
		if(goal > 15000)
		{
			cout << "N ";
			continue;
		}
		
		if(check[goal][N+1] == 1)
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
	
	return 0;
}
