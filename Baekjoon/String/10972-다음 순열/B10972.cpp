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
int num[10010];

int main(void)
{
//	freopen("B10972_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	
	bool flag = false;
	int stopIdx = 0;
	
	for(int i = N-2; i >= 0; i--)
	{
		for(int j = N-1; j > i; j--)
		{
			if(num[i] < num[j])
			{
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				
				flag = true;
				stopIdx = i;
				
				break;
			}
		}
		
		if(flag)
		{
			sort(num+stopIdx+1, num+N);
			
			break;
		}
	}
	
	if(flag)
	{
		for(int i = 0; i < N; i++)
		{
			cout << num[i] << " ";
		}	
	}
	else
	{
		cout << -1;
	}
	
	return 0;
}
