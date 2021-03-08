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

int N;
map<string, int> car;
vector<int> order;

int main(void)
{
//	freopen("B2002_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		
		car[s] = i;
	}
	
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		
		order.push_back(car[s]);
	}
	
	int cnt = 0;
	int idx = -1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = idx+1; j < order.size(); j++)
		{
			if(order[j] == i)
			{
				idx = j;
				cnt++;
			}
		}
	}
	
	cout << N-cnt;
	
	return 0;
}
