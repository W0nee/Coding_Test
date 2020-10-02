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

int N;
long long cnt0;
long long cnt1;

string cal(string temp0, string temp1, int step)
{
	if(temp0.size() < temp1.size())
	{
		int cnt = temp1.size() - temp0.size();
		
		for(int i = 1; i <= cnt; i++)
		{
			temp0 = "0" + temp0;
		}
	}
	else
	{
		int cnt = temp0.size() - temp1.size();
		
		for(int i = 1; i <= cnt; i++)
		{
			temp1 = "0" + temp1;
		}
	}
	
	string result;
	int carry = 0;
	
	if(step == 1)
	{
		for(int i = temp1.size()-1; i >= 0; i--)
		{			
			int num0 = temp0[i] - '0';
			int num1 = temp1[i] - '0';
			int sum = carry + num0 + num1;
			
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
	}
	else
	{
		for(int i = temp1.size()-1; i >= 0; i--)
		{	
			int num0 = temp0[i] - '0';
			int num1 = temp1[i] - '0';
			int sum = carry + num0 + num1;
					
			if(i == temp1.size()-1)
			{
				sum -= 1;	
			}
			
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
	}
	
	return result;
}

int main(void)
{
//	freopen("B2226_input.txt", "r", stdin);
	
	cin >> N;
	
	string cnt0 = "0";
	string cnt1 = "1";
	
	for(int i = 2; i <= N; i++)
	{
		string temp0 = cnt0;
		string temp1 = cnt1;
		
		if(i % 2)
		{
			cnt0 = cal(temp0, temp1, 2);
			cnt1 = cal(temp0, temp1, 1);
		}
		else
		{
			cnt0 = cal(temp0, temp1, 1);
			cnt1 = cal(temp0, temp1, 1);
		}
	}
	
	cout << cnt0;
	
	return 0;
}
