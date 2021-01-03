#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string s;
int check[20];
int Max = -999999999;

int cal(int num1, int num2, string oper)
{
	if(oper == "+")
	{
		return num1 + num2;
	}
	else if(oper == "-")
	{
		return num1 - num2;
	}
	else if(oper == "*")
	{
		return num1 * num2;
	}
}

int solve()
{
	vector<string> ex;
	for(int i = 0; i < s.size();)
	{
		if(check[i] == 1)
		{
			string temp = "";
			temp += s[i+1];
			
			ex.push_back(to_string(cal(s[i]-'0', s[i+2]-'0', temp)));
			i += 3;
		}
		else
		{
			string temp = ""; temp += s[i];
			ex.push_back(temp);
			i++;
		}
	}
	
	int val = stoi(ex[0]);
	for(int i = 2; i < ex.size(); i += 2)
	{
		val = cal(val, stoi(ex[i]), ex[i-1]);
	}
	
	return val;
}

void combination(int idx)
{
	if(idx >= s.size())
	{
		Max = max(Max, solve());
		
		return;
	}

	if(idx+2 < s.size())
	{
		check[idx] = 1;
		check[idx+2] = 1;
		combination(idx+4);
		check[idx] = 0;
		check[idx+2] = 0;	
	}
	
	combination(idx+2);
}

int main(void)
{
//	freopen("B16637_input.txt", "r", stdin);
	
	cin >> N >> s;
	
	combination(0);
	
	cout << Max;
	
	return 0;
}
