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
int idx;
int cnt[100];

void divide(int n)
{
	if(n == 0)
	{
		if(idx+1 == N)
		{
			cout << "m" << endl;
		}
		else if(idx+2 == N || idx+3 == N)
		{
			cout << "o" << endl;
		}
		
		idx += 3;
		return;
	}
	
	divide(n-1);
	
	if(++idx == N)
	{
		cout << "m" << endl;
		return;
	}
	
	for(int i = 1; i <= n+2; i++)
	{
		if(++idx == N)
		{
			cout << "o" << endl;
			return;
		}
	}
	
	divide(n-1);	
}

int main(void)
{
//	freopen("B5904_input.txt", "r", stdin);

	cin >> N;
	
	int stop = 0;
	cnt[0] = 3;
	for(int i = 1; i <= 100; i++)
	{
		cnt[i] = 2*cnt[i-1] + i+3;
		
		if(cnt[i] >= N)
		{
			stop = i;
			break;
		}
	}
	
	divide(stop);
	
	return 0;
}
