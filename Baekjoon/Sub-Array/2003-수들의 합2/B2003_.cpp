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

int N, M;
int num[10010];
int cnt;

int main(void)
{
//	freopen("B2003_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		int sum = 0;
		
		for(int j = i; j <= N; j++)
		{
			sum += num[j];
			
			if(sum == M)
			{
				cnt++;
			}
			else if(sum > M)
			{
				break;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
