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

int T;
string s;
bool palin, similar;

void check(int left, int right, int cnt)
{
	if(left > right)
	{
		if(cnt == 0)
		{
			palin = true;
		}
		else if(cnt == 1)
		{
			similar = true;
		}
		
		return;
	}
	
	if(s[left] == s[right])
	{
		check(left+1, right-1, cnt);
	}
	else
	{
		if(cnt == 0)
		{
			if(s[left+1] == s[right])
			{
				check(left+1, right, cnt+1);
			}
			
			if(s[left] == s[right-1])
			{
				check(left, right-1, cnt+1);	
			}
		}
	}
}

int main(void)
{
//	freopen("B17609_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> s;
		
		palin = false;
		similar = false;
		
		check(0, s.size()-1, 0);
		
		if(palin)
		{
			cout << "0\n";
		}
		else if(similar)
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
