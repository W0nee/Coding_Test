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
vector<string> list;

int main(void)
{
//	freopen("B17413_input.txt", "r", stdin);
	
	getline(cin, s);
	
	bool flag = false;
	string word = "";
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '<')
		{
			flag = true;
			list.push_back(word);	
			word.clear();
			word += s[i];
			
			continue;
		}
		else if(s[i] == '>')
		{
			flag = false;
			word += s[i];
			list.push_back(word);
			word.clear();
			
			continue;
		}
		
		if(flag == false && s[i] == ' ') 
		{
			list.push_back(word);
			word.clear();		
			list.push_back(" ");
			
			continue;
		}
		
		word += s[i];
	}
	
	if(!word.empty())
	{
		list.push_back(word);
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		if(list[i][0] != '<')
		{
			reverse(list[i].begin(), list[i].end());
		}
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i];
	}
	
	return 0;
}
