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

int check()
{
	if('G' <= s[0] && s[0] <= 'Z')
	{
		return 0;
	}	
	
	string chkS = "";
	char now = s[0];
	chkS += now;
	
	for(int i = 1; i < s.size(); i++)
	{
		if(now != s[i])
		{
			chkS += s[i];
			now = s[i];
		}	
	}
		
	if(chkS.size() == 3)
	{
		if(chkS == "AFC")
		{
			return 1;
		}
	}
	else if(chkS.size() == 4)
	{
		string tempS1 = chkS.substr(0, 3);
		string tempS2 = chkS.substr(1, 3);

		if(tempS1 == "AFC" && 'A' <= chkS[3] && chkS[3] <= 'F')
		{
			return 1;
		}
		else if('A' <= chkS[0] && chkS[0] <= 'F' && tempS2 == "AFC")
		{
			return 1;
		}
	}
	else if(chkS.size() == 5)
	{
		string tempS = chkS.substr(1, 3);
		
		if('A' <= chkS[0] && chkS[0] <= 'F' && tempS == "AFC" && 'A' <= chkS[4] && chkS[4] <= 'F')
		{
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B9342_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> s;
		
		if(check())
		{
			cout << "Infected!\n";
		}
		else
		{
			cout << "Good\n";
		}
	}
	
	return 0;
}
