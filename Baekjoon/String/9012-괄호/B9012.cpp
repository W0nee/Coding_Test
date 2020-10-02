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

int solve()
{
	stack<char> st;
		
	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			st.push(s[i]);
		}
		else
		{
			if(st.empty())
			{
				return 0;
			}
			else
			{
				st.pop();
			}
		}
	}
	
	if(st.empty())
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
//	freopen("B9012_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		if(solve())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	
	return 0;
}
