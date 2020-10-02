#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, L, K;
int p[100010];
int a[100010];

int main(void)
{
//	freopen("B3163_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N >> L >> K;	
		
		vector<int> left;
		vector<int> right;
		
		for(int i = 0; i < N; i++)
		{
			cin >> p[i] >> a[i];
			
			if(a[i] > 0)
			{
				right.push_back(L-p[i]);
			}
			else
			{
				left.push_back(p[i]);
			}
		}
		
		vector<int> v = left;
		for(int i = 0; i < right.size(); i++)
		{
			v.push_back(right[i]);
		}
		
		
	}
	
	
	
	return 0;
}
