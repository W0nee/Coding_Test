#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;

int main(void)
{
//	freopen("B10211_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		int psum[100010] = {0};
		
		for(int i = 1; i <= N; i++)
		{
			int num; 
			cin >> num;
			
			psum[i] = psum[i-1] + num;
		}
		
		int Min = 0;
		int Max = -999999999;
		for(int i = 1; i <= N; i++)
		{
			Min = min(psum[i], Min);
			Max = max(psum[i] - Min, Max);
		}
		
		cout << Max << "\n";
	}
	
	return 0;
}
