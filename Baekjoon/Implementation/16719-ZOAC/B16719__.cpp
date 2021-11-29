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

void solve(int left, int right)
{
	char Min = 'Z' + 1;
	int minIdx = -1;
		
	for(int i = left; i < right; i++)
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
	
	if(minIdx == -1)
	{
		return;
	}
		
	word[minIdx] = Min;
	print();
		
	solve(minIdx, right);
	solve(left, minIdx);
}

int main(void)
{
//	freopen("B16719_input.txt", "r", stdin);

	cin >> s;
	
	solve(0, s.size());
	
	return 0;
}
