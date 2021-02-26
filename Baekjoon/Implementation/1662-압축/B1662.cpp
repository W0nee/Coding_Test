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

string s, ss;

int solve()
{
	stack<string> st;
	int result = 0;
	
	for(int i = 0; i < ss.size(); i++)
	{
		if(ss[i] == ')')
		{
			int val = 0;
			
			while(st.top() != "(")
			{
				val += stoi(st.top());
				st.pop();
			}
			st.pop(); // ( Á¦°Å
			
			int multi = stoi(st.top()); // °ö¼À 
			st.pop(); 
			
			st.push(to_string(multi * val));
		}
		else 
		{
			string temp = "";
			temp += ss[i];
			
			st.push(temp);
		}	
	}
	
	while(!st.empty())
	{
		result += stoi(st.top());
		st.pop();
	}
	
	return result;
}

int main(void)
{
//	freopen("B1662_input.txt", "r", stdin);
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9' && s[i+1] == '(')
		{
			ss += s[i];
			ss += s[i+1];
			i++;
		}
		else if('0' <= s[i] && s[i] <= '9')
		{
			ss += "1";
		}
		else
		{
			ss += s[i];
		}
	}

	cout << solve();
	
	return 0;
}
