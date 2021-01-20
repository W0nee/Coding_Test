#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

string a, b;

string cal()
{
	string result;
	int carry = 0;
	
	for(int i = a.size()-1; i >= 0; i--)
	{
		int num1 = a[i] - '0';
		int num2 = b[i] - '0';
		int sum = carry + num1 + num2;
		
		carry = 0;
		
		if(sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		
		result = to_string(sum) + result;
	}
	
	if(carry)
	{
		result = "1" + result;
	}

	return result;
}

int main(void)
{
//	freopen("B10757_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	if(a.size() < b.size())
	{
		int cnt = b.size()-a.size();
		
		for(int i = 1; i <= cnt; i++)
		{
			a = "0" + a;
		}
	}
	else if(b.size() < a.size())
	{
		int cnt = a.size()-b.size();
		
		for(int i = 1; i <= cnt; i++)
		{
			b = "0" + b;
		}
	}
	
	cout << cal();
	
	return 0;
}
