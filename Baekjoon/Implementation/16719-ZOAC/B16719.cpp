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
char result[110];
int visited[110];

string ctos()
{
	string temp = "";
	
	for(int i = 0; i < s.size(); i++)
	{
		if(result[i] != '\0')
		{
			temp += result[i];
		}
	}
	
	return temp;
}

void print()
{
	for(int i = 0; i < s.size(); i++)
	{
		if(result[i] == '\0')
		{
			continue;
		}
		else
		{
			cout << result[i];
		}
	}
	cout << "\n";
}

int main(void)
{
//	freopen("B16719_input.txt", "r", stdin);
	
	cin >> s;

	int n = s.size();
	int idx = -1;
	
	while(n--)
	{
		// init
		string Min = "";
		for(int i = 0; i <= s.size(); i++)
		{
			Min += "Z";
		}
		
		// µÚÂÊ Å½»ö 
		for(int i = 0; i < s.size(); i++)
		{
			if(result[i] == '\0')
			{
				result[i] = s[i];
				
				string temp = ctos();
				if(temp < Min)
				{
					Min = temp;
					idx = i;
				}
				
				result[i] = '\0';	
			}
		}
		result[idx] = s[idx];
		
		print();
	}
	
	return 0;
}
