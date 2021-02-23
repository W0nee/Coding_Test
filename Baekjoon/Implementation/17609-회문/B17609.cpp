#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string s;
bool zero;
bool one;

void check(int left, int right, int cnt)
{
	if(cnt >= 2)
	{
		return;
	}
	else if(left >= right)
	{
		if(cnt == 0)
		{
			zero = true;
		}
		else
		{
			one = true;
		}
		
		return;
	}
	
	if(s[left] == s[right])
	{
		check(left+1, right-1, cnt);
	}
	else
	{
		check(left+1, right, cnt+1);
		check(left, right-1, cnt+1);
	}
	
	if(zero || one)
	{
		return;
	}
}

int main(void)
{
//	freopen("B17609_input.txt", "r", stdin);

	cin >> N;
	
	for(int k = 1; k <= N; k++)
	{
		zero = false;
		one = false;
		
		cin >> s;
		
		check(0, s.size()-1, 0);
		
		if(zero)
		{
			cout << "0\n";
		}
		else if(one)
		{
			cout << "1\n";
		}
		else
		{
			cout << "2\n";
		}
	}
	
	return 0;
}
