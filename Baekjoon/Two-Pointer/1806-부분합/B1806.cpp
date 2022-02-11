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

int N, S;
int num[100010];

int main(void)
{
//	freopen("B1806_input.txt", "r", stdin);
	
	cin >> N >> S;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	int left = 1;
	int right = 1;
	int sum = 0;
	int len = N + 1;
	
	while(left <= right && right <= N+1)
	{
		if(sum < S)
		{
			sum += num[right++];
		}			
		else
		{
			len = min(len, right - left);
			sum -= num[left++];
		}
	}
	
	if(len == N+1)
	{
		cout << "0";	
	} 	
	else 
	{
		cout << len;	
	}
	
	return 0;
}
