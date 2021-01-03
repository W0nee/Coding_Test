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
int a, b;
int cnt = 1;

int main(void)
{
//	freopen("B1057_input.txt", "r", stdin);
	
	cin >> N >> a >> b;
	
	if(a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
	while(1)
	{
		if(b - a == 1 && b % 2 == 0)
		{
			break;
		}
		
		a = (a+1) / 2;
		b = (b+1) / 2;
		
		cnt++;	
	}
	
	cout << cnt;
	
	return 0;
}
