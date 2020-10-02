#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 999999999

int A[11];
int B[11];
int aWin, bWin;

int main(void)
{
//	freopen("B10803_input.txt", "r", stdin);
	
	for(int i = 1; i <= 10; i++)
	{
		cin >> A[i];
	}
	
	for(int i = 1; i <= 10; i++)
	{
		cin >> B[i];
	}
	
	for(int i = 1; i <= 10; i++)
	{
		if(A[i] > B[i])
		{
			aWin++;
		}
		else if(A[i] < B[i])
		{
			bWin++;
		}
	}
	
	if(aWin > bWin)
	{
		cout << "A";
	}
	else if(aWin < bWin)
	{
		cout << "B";
	}
	else
	{
		cout << "D";
	}
	
	return 0;
}
