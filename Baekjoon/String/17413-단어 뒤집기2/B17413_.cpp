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
stack<char> st;
vector<string> list;

int main(void)
{
//	freopen("B17413_input.txt", "r", stdin);
	
	getline(cin, s);
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '<')
		{
			string word = "";
			
			while(!st.empty())
			{
				word = st.top() + word;
				st.pop();	
			}
			
			reverse(word.begin(), word.end());
			
			list.push_back(word);
			word.clear();
			
			while(1)
			{
				word += s[i];
				
				if(s[i] == '>')
				{
					list.push_back(word);
					break;
				}
				
				i++;
			}
			
			continue;
		}
		else if(s[i] == ' ')
		{
			string word = "";
			
			while(!st.empty())
			{
				word = st.top() + word;
				st.pop();	
			}
			
			reverse(word.begin(), word.end());
			word += " ";
			
			list.push_back(word);
			continue;
		}
		
		st.push(s[i]);
	}
	
	if(!st.empty())
	{
		string word = "";
			
		while(!st.empty())
		{
			word = st.top() + word;
			st.pop();	
		}
		
		reverse(word.begin(), word.end());
		
		list.push_back(word);
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i];
	}
	
	return 0;
}
