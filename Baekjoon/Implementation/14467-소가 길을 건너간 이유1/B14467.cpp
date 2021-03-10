#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> cow[110];
int cnt;

int main(void)
{
//	freopen("B14467_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int num, where;
		cin >> num >> where;
		
		cow[num].push_back(where);
	}
	
	for(int i = 1; i <= 10; i++)
	{		
		if(cow[i].size() >= 2)
		{
			for(int j = 0; j < cow[i].size()-1; j++)
			{
				if(cow[i][j] != cow[i][j+1])
				{
					cnt++;			
				}
			}	
		}
	}
	
	cout << cnt;
	
	return 0;
}
