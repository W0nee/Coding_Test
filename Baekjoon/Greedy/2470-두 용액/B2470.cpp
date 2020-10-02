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
vector<long long> v;
long long MaxA;
long long MaxB;
long long Min = 9999999999;

bool cmp(long long a, long long b)
{
	if(abs(a) < abs(b))
	{
		return true;
	}
	
	return false;
}

int main(void)
{
//	freopen("B2470_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		long long input;
		cin >> input;
		
		v.push_back(input);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < v.size()-1; i++)
	{
		long long result = abs(v[i] + v[i+1]);
		
		if(result < Min)
		{
			Min = result;
			MaxA = v[i];
			MaxB = v[i+1];
		}
	}
	
	if(MaxA < MaxB)
	{
		cout << MaxA << " " << MaxB;
	}
	else
	{
		cout << MaxB << " " << MaxA;
	}
	
	return 0;
}
