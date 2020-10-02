#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> bulk;
int result[55];

int main(void)
{
//	freopen("B7568_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int kg, cm;
		cin >> kg >> cm;
		
		bulk.push_back({kg, cm});
	}	
	
	for(int i = 0; i < bulk.size(); i++)
	{
		int rank = 1;
		
		for(int j = 0; j < bulk.size(); j++)
		{
			if(i == j)
			{
				continue;
			}
			
			if(bulk[i].first < bulk[j].first && bulk[i].second < bulk[j].second)
			{
				rank++;
			}
		}
			
		result[i] = rank;
	}
	
	for(int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
