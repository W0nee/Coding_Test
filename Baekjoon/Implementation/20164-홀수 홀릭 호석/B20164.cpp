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

string N;
int Max, Min = 987654321;

int cal(string x, int left, int right)
{
	string num = "";
	
	for(int i = left; i < right; i++)
	{
		num += x[i];
	}
		
	return stoi(num);
}

int count_hol(string x)
{
	int cnt = 0;
	
	for(int i = 0; i < x.size(); i++)
	{
		if((x[i]-'0') % 2 == 1)
		{
			cnt++;
		}
	}
	
	return cnt;
}

void divide(string x, int val)
{
	if(x.size() >= 3)
	{
		for(int i = 1; i < x.size(); i++)
		{
			for(int j = i+1; j < x.size(); j++)
			{
				int n1 = cal(x, 0, i);
				int n2 = cal(x, i, j);
				int n3 = cal(x, j, (int)x.size());
				
				string nx = to_string(n1 + n2 + n3);
				
				divide(nx, val + count_hol(x));
			}
		}	
	}
	else if(x.size() == 2)
	{
		int n1 = x[0]-'0';
		int n2 = x[1]-'0';
		
		string nx = to_string(n1 + n2);
		
		divide(nx, val + count_hol(x));
	}
	else if(x.size() == 1)
	{
		val += count_hol(x);
		
		Max = max(Max, val);
		Min = min(Min, val);
		
		return;
	}
}

int main(void)
{
//	freopen("B20164_input.txt", "r", stdin);
	
	cin >> N;
	
	divide(N, 0);
	
	cout << Min << " " << Max;
	
	return 0;
}
