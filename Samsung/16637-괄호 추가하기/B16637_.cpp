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
vector<int> num;
vector<char> oper;
int check[20];
int Max = -999999999;

int cal(int num1, int num2, char oper)
{
	if(oper == '+')
	{
		return num1 + num2;
	}
	else if(oper == '-')
	{
		return num1 - num2;
	}
	else if(oper == '*')
	{
		return num1 * num2;
	}
}

int solve()
{
	vector<int> tempNum;
	vector<char> tempOper;
	
	for(int i = 0; i < num.size(); i++)
	{
		if(check[i] == 1)
		{
			tempNum.push_back(cal(num[i], num[i+1], oper[i]));
			tempOper.push_back(oper[i+1]);
			i++;
		}
		else
		{
			tempNum.push_back(num[i]);
			if(i != num.size()-1)
			{
				tempOper.push_back(oper[i]);	
			}
		}
	}
	
	int result = tempNum[0];
	for(int i = 1; i < tempNum.size(); i++)
	{
		result = cal(result, tempNum[i], tempOper[i-1]);
	}
	
	return result;
}

void combination(int idx)
{
	if(idx >= num.size())
	{
		Max = max(Max, solve());
		
		return;
	}

	if(idx+1 < num.size())
	{
		check[idx] = 1;
		check[idx+1] = 1;
		combination(idx+2);
		check[idx] = 0;
		check[idx+1] = 0;	
	}
	
	combination(idx+1);
}

int main(void)
{
//	freopen("B16637_input.txt", "r", stdin);
	
	cin >> N >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(i % 2 == 0)
		{
			num.push_back(s[i]-'0');
		}
		else
		{
			oper.push_back(s[i]);
		}
	}
	
	combination(0);
	
	cout << Max;
	
	return 0;
}
