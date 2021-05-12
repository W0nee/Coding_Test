#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string result;

int isPrime()
{
	int num = stoi(result);
	
	for(int i = 2; i <= sqrt(num); i++)
	{
		if(num % i == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

void solve(int cnt)
{
	if(cnt == N)
	{
		cout << result << endl;
		return;	
	}
	
	for(int i = 0; i <= 9; i++)
	{
		if(cnt == 0 && (i == 0 || i == 1))
		{
			continue;
		}
		
		result += to_string(i);
		if(isPrime() == 1)
		{
			solve(cnt+1);	
		}
		result.pop_back();
	}
}

int main(void)
{
//	freopen("B2023_input.txt", "r", stdin);

	cin >> N;
	
	solve(0);
	
	return 0;
}
