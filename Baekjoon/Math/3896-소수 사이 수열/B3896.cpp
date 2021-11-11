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

int T, N;
int prime[1300000];

void eratos()
{
	for(int i = 2; i <= 1300000; i++)
	{
		prime[i] = i;
	}
	
	for(int i = 2; i <= 1300000; i++)
	{
		if(prime[i] == 0)
		{
			continue;
		}
		else
		{
			for(int j = i + i; j <= 1300000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int check(int num)
{
	int first;
	int second;
	
	int temp = num;
	while(1)
	{
		if(prime[temp] != 0)
		{
			first = temp;
			break;
		}
		temp--;
	}
	
	temp = num;	
	while(1)
	{
		if(prime[temp] != 0)
		{
			second = temp;
			break;
		}
		temp++;
	}
	
	return second - first;
}

int main(void)
{
//	freopen("B3896_input.txt", "r", stdin);
	
	cin >> T;
	
	eratos();
	
	while(T--)
	{
		cin >> N;
		
		if(prime[N] != 0)
		{
			cout << "0\n";
		}
		else
		{
			cout << check(N) << "\n";
		}
	}
	
	return 0;
}
