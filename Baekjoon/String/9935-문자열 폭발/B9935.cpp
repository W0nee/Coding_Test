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
string c4;
vector<char> v;

int main(void)
{
//	freopen("B9935_input.txt", "r", stdin);
	
	cin >> s >> c4;
	
	for(int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i]);
		
		if(s[i] == c4[c4.size()-1])
		{
			int idx = v.size()-1;
			for(int j = c4.size()-1; j >= 0; j--)
			{
				if(v[idx] != c4[j])
				{
					break;
				}
				
				idx--;
				
				if(j == 0)
				{
					for(int k = 1; k <= c4.size(); k++)
					{
						v.pop_back();	
					}
				}
			}
		}
	}
	
	if(v.size() == 0)
	{
		cout << "FRULA";
	}
	else
	{
		for(int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}	
	}
	
	return 0;
}
