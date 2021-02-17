#include <stdio.h>
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

int T;
string s;
string temp;

void R(deque<string> &num, int &Reverse)
{
	if(Reverse == 0) Reverse = 1;
	else Reverse = 0;
}

void D(deque<string> &num, int &Reverse)
{
	if(Reverse == 0)
	{
		num.pop_front();	
	}
	else
	{
		num.pop_back();
	}
}

int main(void)
{
//	freopen("B5430_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		string command;
		string s;
		deque<string> num;
		int Reverse = 0;
		bool Stop = false;
		int N;
		
		cin >> command >> N >> s;
		
		string temp = "";
		for(int i = 1; i <= s.size()-2; i++)
		{
			if(s[i] == ',')
			{
				num.push_back(temp);
				temp.clear();
			}
			else
			{
				temp += s[i];
			}
		}
		if(temp != "")
		{
			num.push_back(temp);	
		}
		
		for(int i = 0; i < command.size(); i++)
		{
			if(command[i] == 'R')
			{
				R(num, Reverse);
			}
			else
			{
				if(num.size() == 0)
				{
					cout << "error\n";
					Stop = true;
					break;
				}
				else
				{
					D(num, Reverse);	
				}
			}
		}
		
		if(Stop)
		{
			continue;
		}
		
		cout << "[";
		for(int i = 0; i < num.size(); i++)
		{
			if(i == num.size()-1)
			{
				cout << num[i];
			}
			else
			{
				cout << num[i] << ",";
			}
		}
		cout << "]\n";	
	}
	
	return 0;
}
