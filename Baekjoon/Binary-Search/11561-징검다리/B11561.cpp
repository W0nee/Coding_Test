#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int T;
unsigned long long N;

unsigned long long check(unsigned long long n)
{
	if(n*(n+1) / 2 <= N)
	{
		return 1;	
	}	
	else
	{
		return 0;
	}
}

int main(void)
{
//	freopen("B11561_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		unsigned long long left = 1;
		unsigned long long right = N;
		unsigned long long Max = 0;
		
		while(left <= right)
		{
			unsigned long long mid = (left + right) / 2;
			
			if(check(mid))
			{
				Max = max(Max, mid);
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		
		cout << Max << "\n";
	}
	
	return 0;
}
