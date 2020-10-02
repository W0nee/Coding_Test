#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string s;
stack<char> st;
int ans;

int main(void)
{
//	freopen("B10799_input.txt", "r", stdin);

	cin >> s;
	
	for(int i = 0; i < s.size(); i++)	
	{
		if(s[i] == '(')
		{
			st.push(s[i]);
		}
		else
		{
			if(s[i-1] == '(')
			{
				st.pop();
				ans += st.size();
			}
			else
			{
				ans += 1;
				st.pop();
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
