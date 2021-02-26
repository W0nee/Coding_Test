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

int check_right()
{
	stack<char> st;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ')' || s[i] == ']')
		{
			if(s[i] == ')')
			{
				if(st.empty())
				{
					return 0;
				}
				
				if(st.top() == '(')
				{
					st.pop();
				}
				else
				{
					return 0;
				}
			}
			else if(s[i] == ']')
			{
				if(st.empty())
				{
					return 0;
				}
				
				if(st.top() == '[')
				{
					st.pop();
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			st.push(s[i]);
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

int cal()
{
	stack<string> st;
	int result = 0;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ')' || s[i] == ']')
		{
			if(s[i] == ')')
			{
				if(st.top() != "(")
				{
					int val = 0;
					
					while(st.top() != "(")
					{
						val += stoi(st.top());
						st.pop();
					}
					st.pop();
					
					val *= 2;
					st.push(to_string(val));
				}
				else
				{
					st.pop();
					st.push("2");
				}
			}
			else if(s[i] == ']')
			{
				if(st.top() != "[")
				{
					int val = 0;
					
					while(st.top() != "[")
					{
						val += stoi(st.top());
						st.pop();
					}
					st.pop();
					
					val *= 3;
					st.push(to_string(val));
				}
				else
				{
					st.pop();
					st.push("3");
				}
			}
		}
		else
		{
			if(s[i] == '(')
			{
				st.push("(");
			}
			else
			{
				st.push("[");	
			}
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
//	freopen("B2504_input.txt", "r", stdin);
	
	cin >> s;
	
	if(check_right() == 0)
	{
		cout << "0";
	}
	else
	{
		cout << cal();
	}
	
	return 0;
}
