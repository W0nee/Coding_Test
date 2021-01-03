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
string cnt;

void add(string val, int step)
{
	string result = "";
	
	int n = cnt.size()-val.size();
	for(int i = 1; i <= n; i++)
	{
		val = "0" + val;
	}
	
	// plus
	if(step == 1)
	{
		int carry = 0;
		for(int i = val.size()-1; i >= 0; i--)
		{
			int cnt_num = cnt[i]-'0';
			int val_num = val[i]-'0';
			int sum = cnt_num + val_num + carry;
			
			if(sum >= 10)
			{
				carry = 1;
				sum -= 10;
			}
			else
			{
				carry = 0;
			}
			
			result = to_string(sum) + result;
		}	
		
		if(carry == 1)
		{
			result = "1" + result;
		}
	}
	// minus
	else
	{
		int carry = 0;
		for(int i = val.size()-1; i >= 0; i--)
		{
			int cnt_num = cnt[i]-'0';
			int val_num = val[i]-'0';
			int sum = cnt_num - val_num - carry;
			
			if(sum < 0)
			{
				carry = 1;
				sum += 10;
			}
			else
			{
				carry = 0;
			}
			
			result = to_string(sum) + result;
		}	
	}
	
	cnt = result;
}

int main(void)
{
//	freopen("B2226_input.txt", "r", stdin);
	
	cin >> N;
	
	cnt = "0";
	
	for(int i = 2; i <= N; i++)
	{
		if(i % 2 == 0)
		{
//			cnt[i] = cnt[i-1]*2 + 1;
			add(cnt, 1);
			add("1", 1);
		}
		else
		{
//			cnt[i] = cnt[i-1]*2 - 1;
			add(cnt, 1);
			add("1", 2);
		}
	}

	cout << cnt;
	
	return 0;
}
