#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int num[100010];
int Min = 999999999;

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
	int sum = num[1];
	
	while(left <= right && right <= N)
	{
		if(sum < S)
		{
			sum += num[++right];
		}
		else
		{
			Min = min(Min, right-left+1);
			sum -= num[left++];
		}
	}
	
	if(Min == 999999999)
	{
		cout << "0";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
