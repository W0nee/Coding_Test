#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<int> Plus;
vector<int> Minus;
vector<int> Zero;
int Max;

int main(void)
{
//	freopen("B1744_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		
		if(input > 0)
		{
			Plus.push_back(input);	
		}
		else if(input < 0)
		{
			Minus.push_back(input);
		}
		else
		{
			Zero.push_back(input);
		}
	}
	
	sort(Plus.begin(), Plus.end());
	sort(Minus.begin(), Minus.end(), greater<int>());
	
	while(Plus.size() >= 2)
	{
		int val1 = Plus[Plus.size()-1] * Plus[Plus.size()-2];
		int val2 = Plus[Plus.size()-1] + Plus[Plus.size()-2];
		
		if(val1 > val2)
		{
			Max += val1;	
		}
		else
		{
			Max += val2;	
		}
		
		Plus.pop_back();
		Plus.pop_back();
	}
	while(Plus.size() >= 1)
	{
		Max += Plus[Plus.size()-1];
		Plus.pop_back();
	}
	
	while(Minus.size() >= 2)
	{
		Max += Minus[Minus.size()-1] * Minus[Minus.size()-2];
		Minus.pop_back();
		Minus.pop_back();
	}
	while(Minus.size() >= 1)
	{
		if(Zero.size() >= 1)
		{
			Minus.pop_back();
		}
		else
		{
			Max += Minus[Minus.size()-1];
			Minus.pop_back();
		}
	}
	
	cout << Max;
	
	return 0;
}
