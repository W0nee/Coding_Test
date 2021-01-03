#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int arow, acol;
int brow, bcol;

int a[110][110];
int b[110][110];
int c[110][110];

void solve()
{
	for(int i = 1; i <= arow; i++)
	{
		for(int j = 1; j <= bcol; j++)
		{
			for(int k = 1; k <= brow; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}	
	}	

}

int main(void)
{
//	freopen("B2470_input.txt", "r", stdin);
	
	cin >> arow >> acol;
	for(int i = 1; i <= arow; i++)
	{
		for(int j = 1; j <= acol; j++)
		{
			cin >> a[i][j];
		}
	}
	
	cin >> brow >> bcol;
	for(int i = 1; i <= brow; i++)
	{
		for(int j = 1; j <= bcol; j++)
		{
			cin >> b[i][j];
		}
	}
	
	solve();
	
	for(int i = 1; i <= arow; i++)
	{
		for(int j = 1; j <= bcol; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
