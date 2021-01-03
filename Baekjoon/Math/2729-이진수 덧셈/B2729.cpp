#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
string a, b;
string result;
string ans;

void cal()
{
	int up = 0;
	
	for(int i = a.size()-1; i >= 0; i--)
	{
		if(up == 0)
		{
			if(a[i] == '0' && b[i] == '0')
			{
				result = "0" + result;
				up = 0;
			}
			else if(a[i] == '1' && b[i] == '1')
			{
				result = "0" + result;
				up = 1;
			}
			else
			{
				result = "1" + result;
				up = 0;
			}	
		}
		else
		{
			if(a[i] == '0' && b[i] == '0')
			{
				result = "1" + result;
				up = 0;
			}
			else if(a[i] == '1' && b[i] == '1')
			{
				result = "1" + result;
				up = 1;
			}
			else
			{
				result = "0" + result;
				up = 1;
			}	
		}
	}
	
	if(up == 1)
	{
		result = "1" + result;
	}
}

int main(void)
{
//	freopen("B2729_input.txt", "r", stdin);
	
	cin >> T;
		
	while(T--)
	{
		ans.clear();
		result.clear();
		
		cin >> a >> b;
	
		if(a.size() > b.size())
		{
			string temp = a;
			a = b;
			b = temp;	
		}
		
		int cnt = b.size()-a.size();
		for(int i = 1; i <= cnt; i++)
		{
			a = "0" + a;
		}
		
		cal();
		
		int check = 0;
		for(int i = 0; i < result.size(); i++)
		{
			if(result[i] == '1')
			{
				check = 1;
			}
			
			if(check == 1)
			{
				ans += result[i];	
			}
		}
		
		if(check == 1)
		{
			cout << ans << "\n";	
		}
		else
		{
			cout << "0\n";
		}	
	}
	
	return 0;
}
