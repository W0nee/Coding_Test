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
int order;
int result[110];

int main(void)
{
//	freopen("B2605_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> order;
		
		int idx = i - order;
		
		for(int j = N-1; j >= idx; j--)
		{
			result[j+1] = result[j];
		}
		result[idx] = i;
	}

	for(int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
