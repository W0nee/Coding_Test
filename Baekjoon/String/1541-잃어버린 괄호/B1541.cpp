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
int result;

int main(void)
{
//	freopen("B1541_input.txt", "r", stdin);
	
	cin >> s;
	
	string now;
	bool flag = false;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '+' || s[i] == '-')
		{			
			if(flag)
			{
				result -= stoi(now);
			}
			else
			{
				result += stoi(now);
			}
			
			if(s[i] == '-')
			{
				flag = true;
			}	
			
			now.clear();
		}
		else
		{
			now += s[i];
		}
		
		if(i == s.size()-1)
		{
			if(flag)
			{
				result -= stoi(now);
			}
			else
			{
				result += stoi(now);
			}
		}
	}
	
	cout << result;
	
	return 0;
}
