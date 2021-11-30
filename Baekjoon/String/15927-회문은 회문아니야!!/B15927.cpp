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

string s;

int main(void)
{
//	freopen("B15927_input.txt", "r", stdin);
	
	cin >> s;
	
	bool flag = false;
	char std = s[0];
	
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] != std)
		{
			flag = true;
		}
	}
	
	if(flag)
	{
		int left = 0;
		int right = s.size()-1;
		
		while(left <= right)
		{
			if(s[left] == s[right])
			{
				left++;
				right--;
			}
			else
			{
				break;
			}
		}	
		
		if(left > right)
		{
			cout << s.size()-1;
		}
		else
		{
			cout << s.size();
		}
	}
	else
	{
		cout << "-1";
	}
	
	return 0;
}
