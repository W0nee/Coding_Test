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

string s;
char word[110];

int check(int idx)
{
	for(int i = idx; i < s.size(); i++)
	{
		if(word[i] == '\0')
		{
			return 0;
		}
	}
	
	return 1;
}

void print()
{
	for(int i = 0; i < s.size(); i++)
	{
		if(word[i] != '\0')
		{
			cout << word[i];
		}
	}
	cout << endl;
}

void solve(int idx)
{
	while(!check(idx))
	{
		char Min = 'Z' + 1;
		int minIdx = 0;
		
		for(int i = idx; i < s.size(); i++)
		{
			if(word[i] != '\0')
			{
				continue;
			}
			
			if(Min > s[i])
			{
				Min = s[i];
				minIdx = i;
			}
		}	
		
		word[minIdx] = Min;
		print();
		
		solve(minIdx);
	}
}

int main(void)
{
//	freopen("B16719_input.txt", "r", stdin);

	cin >> s;
	
	solve(0);
	
	return 0;
}
